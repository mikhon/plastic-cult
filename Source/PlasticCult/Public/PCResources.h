// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PCResources.generated.h"

UCLASS()
class PLASTICCULT_API APCResources : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APCResources();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle DecayTimerHandle;

	int32 AwarenessResource;
	int32 LastEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Resource)
	int32 AwarenessResourceMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Resource)
	int32 AwarenessResourceStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Resource)
	int32 EventThreshold1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Resource)
	int32 EventThreshold2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Resource)
	int32 EventThreshold3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Resource)
	int32 EventThreshold4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Resource)
	int32 DropPerEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Resource)
	int32 DecayPerSecond;

	void InitEvents();
	void StartDecayTimer();
	
	UFUNCTION()
	void DecayAwareness();

	UFUNCTION()
	void AddAwareness(int NewAwareness);

	UFUNCTION()
	void NotificationHappens(FString NotificationId, int32 NotificationIndex);

	UFUNCTION()
	void ListenToNotificationHappens(FString NotificationId);

	UFUNCTION()
	void ListenToNotificationClosed(FString NotificationId);

};
