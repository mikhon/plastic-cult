// Fill out your copyright notice in the Description page of Project Settings.


#include "PCResources.h"
#include "PCEvents.h"
#include "PCGameInstance.h"

// Sets default values
APCResources::APCResources()
{
	AwarenessResourceMax = 100;
	AwarenessResourceStart = 60;
	EventThreshold1 = 90;
	EventThreshold2 = 80;
	EventThreshold3 = 70;
	EventThreshold4 = 95;
	DropPerEvent = 25;
	DecayPerSecond = 5;
}

// Called when the game starts or when spawned
void APCResources::BeginPlay()
{
	Super::BeginPlay();
	InitEvents();

	LastEvent = 0;
	AwarenessResource = AwarenessResourceStart;
}

void APCResources::InitEvents()
{
	UPCGameInstance* PCGameInstance = Cast<UPCGameInstance>(GetGameInstance());
	if (PCGameInstance)
	{
		if (PCGameInstance->PCEvents != nullptr)
		{
			PCGameInstance->PCEvents->OnAddResource.AddDynamic(this, &APCResources::AddAwareness);
			PCGameInstance->PCEvents->OnNotificationHappens.AddDynamic(this, &APCResources::ListenToNotificationHappens);
			PCGameInstance->PCEvents->OnNotificationClosed.AddDynamic(this, &APCResources::ListenToNotificationClosed);
			PCGameInstance->PCEvents->OnInitResourcesBar.Broadcast(AwarenessResource, AwarenessResourceMax);
			PCGameInstance->PCEvents->OnUpdateResourceBar.Broadcast(AwarenessResource);
		}
	}
}

void APCResources::StartDecayTimer()
{
	GetWorldTimerManager().SetTimer(DecayTimerHandle, this, &APCResources::DecayAwareness, 1.0f, true);
}

void APCResources::DecayAwareness()
{
	AwarenessResource -= DecayPerSecond;
	UPCGameInstance* PCGameInstance = Cast<UPCGameInstance>(GetGameInstance());
	if (PCGameInstance)
	{
		if (PCGameInstance->PCEvents != nullptr)
		{
			PCGameInstance->PCEvents->OnUpdateResourceBar.Broadcast(AwarenessResource);
		}
	}
	UE_LOG(LogTemp, Log, TEXT("Awareness Total: %d"), AwarenessResource);
}

void APCResources::AddAwareness(int NewAwareness)
{
	AwarenessResource += NewAwareness;
	UPCGameInstance* PCGameInstance = Cast<UPCGameInstance>(GetGameInstance());
	if (PCGameInstance)
	{
		if (PCGameInstance->PCEvents != nullptr)
		{
			PCGameInstance->PCEvents->OnUpdateResourceBar.Broadcast(AwarenessResource);
		}
	}
	if (LastEvent == 0 && AwarenessResource >= EventThreshold1) 
	{
		NotificationHappens(TEXT("Accident1"), 1);
	}
	else if (LastEvent == 1 && AwarenessResource >= EventThreshold2)
	{
		NotificationHappens(TEXT("Accident2"), 2);
	}
	else if (LastEvent == 2 && AwarenessResource >= EventThreshold3)
	{
		NotificationHappens(TEXT("Accident3"), 3);
	}
	else if (LastEvent == 3 && AwarenessResource >= EventThreshold4)
	{
		NotificationHappens(TEXT("Accident4"), 4);
	}
}

void APCResources::NotificationHappens(FString NotificationId, int32 NotificationIndex)
{
	LastEvent = NotificationIndex;
	AwarenessResource -= DropPerEvent;
	UE_LOG(LogTemp, Log, TEXT("Event happens: %s"), *NotificationId);
	UPCGameInstance* PCGameInstance = Cast<UPCGameInstance>(GetGameInstance());
	if (PCGameInstance)
	{
		if (PCGameInstance->PCEvents != nullptr)
		{
			PCGameInstance->PCEvents->OnNotificationHappens.Broadcast(NotificationId);
			PCGameInstance->PCEvents->OnWorkerDies.Broadcast(NotificationIndex);
			PCGameInstance->PCEvents->OnUpdateResourceBar.Broadcast(AwarenessResource);
		}
	}
}

void APCResources::ListenToNotificationHappens(FString NotificationId)
{
	if (NotificationId.Equals(TEXT("StartGame")))
	{
		UPCGameInstance* PCGameInstance = Cast<UPCGameInstance>(GetGameInstance());
		if (PCGameInstance)
		{
			if (PCGameInstance->PCEvents != nullptr)
			{
				PCGameInstance->PCEvents->OnUpdateResourceBar.Broadcast(AwarenessResource);
			}
		}
		StartDecayTimer();
	}
	else
	{
		GetWorldTimerManager().ClearTimer(DecayTimerHandle);
	}
}

void APCResources::ListenToNotificationClosed(FString NotificationId)
{
	StartDecayTimer();
}
