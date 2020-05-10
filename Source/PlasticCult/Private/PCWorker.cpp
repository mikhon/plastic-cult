// Fill out your copyright notice in the Description page of Project Settings.


#include "PCWorker.h"
#include "PCEvents.h"
#include "PCGameInstance.h"

// Sets default values
APCWorker::APCWorker()
{
	WorkerId = 0;
	ProductionPerSecond = 2;
	IsDead = false;
}

// Called when the game starts or when spawned
void APCWorker::BeginPlay()
{
	Super::BeginPlay();

	InitEvents();
}

void APCWorker::InitEvents()
{
	UPCGameInstance* PCGameInstance = Cast<UPCGameInstance>(GetGameInstance());
	if (PCGameInstance)
	{
		if (PCGameInstance->PCEvents != nullptr)
		{
			PCGameInstance->PCEvents->OnWorkerDies.AddDynamic(this, &APCWorker::Die);
			PCGameInstance->PCEvents->OnNotificationHappens.AddDynamic(this, &APCWorker::NotificationHappens);
		}
	}
}

void APCWorker::StartTimer()
{
	GetWorldTimerManager().SetTimer(WorkingTimerHandle, this, &APCWorker::IncreaseAwareness, 1.0f, true);
}

void APCWorker::IncreaseAwareness()
{
	if (IsDead)
	{
		return;
	}
	UPCGameInstance* PCGameInstance = Cast<UPCGameInstance>(GetGameInstance());
	if (PCGameInstance)
	{
		if (PCGameInstance->PCEvents != nullptr)
		{
			PCGameInstance->PCEvents->OnAddResource.Broadcast(ProductionPerSecond);
		}
	}
}

void APCWorker::Die(int32 DyingWorkerId)
{
	if (DyingWorkerId == WorkerId) 
	{
		UE_LOG(LogTemp, Log, TEXT("I died: %d"), WorkerId);
		IsDead = true;
		ProductionPerSecond = 0;
		GetWorldTimerManager().ClearTimer(WorkingTimerHandle);
	}
}

void APCWorker::NotificationHappens(FString NotificationId)
{
	if (NotificationId.Equals(TEXT("StartGame"))) 
	{
		if (!IsDead)
		{
			StartTimer();
		}
	}
	else
	{
		GetWorldTimerManager().ClearTimer(WorkingTimerHandle);
	}
}

void APCWorker::NotificationCloses(FString NotificationId)
{
	if (!IsDead)
	{
		StartTimer();
	}
}
