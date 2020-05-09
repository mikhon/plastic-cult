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
		}
	}
}

void APCResources::AddAwareness(int NewAwareness)
{
	AwarenessResource += NewAwareness;
	UE_LOG(LogTemp, Log, TEXT("Added awareness! Total: %d"), AwarenessResource);
}
