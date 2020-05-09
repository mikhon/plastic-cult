// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PCWorker.generated.h"

UCLASS()
class PLASTICCULT_API APCWorker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APCWorker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle WorkingTimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Worker)
	int32 ProductionPerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Worker)
	bool IsDead;

	void StartTimer();
	void IncreaseAwareness();
	void Die();

};
