// Fill out your copyright notice in the Description page of Project Settings.


#include "PCWorker.h"
#include "PCEvents.h"
#include "PCGameInstance.h"

// Sets default values
APCWorker::APCWorker()
{
	ProductionPerSecond = 1;
	IsDead = false;
}

// Called when the game starts or when spawned
void APCWorker::BeginPlay()
{
	Super::BeginPlay();
	
	if (!IsDead) 
	{
		StartTimer();
	}
}

void APCWorker::StartTimer()
{
	GetWorldTimerManager().SetTimer(WorkingTimerHandle, this, &APCWorker::IncreaseAwareness, 1.0f, true);
}

void APCWorker::IncreaseAwareness()
{
	UPCGameInstance* PCGameInstance = Cast<UPCGameInstance>(GetGameInstance());
	if (PCGameInstance)
	{
		if (PCGameInstance->PCEvents != nullptr)
		{
			PCGameInstance->PCEvents->OnAddResource.Broadcast(ProductionPerSecond);
		}
	}
}

void APCWorker::Die()
{
	IsDead = true;
	GetWorldTimerManager().ClearTimer(WorkingTimerHandle);
}

