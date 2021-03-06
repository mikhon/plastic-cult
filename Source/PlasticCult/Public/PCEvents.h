// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PCEvents.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPlasticDelegate_OnInitResourcesBar, int32, StartAmount, int32, MaxAmount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlasticDelegate_OnAddResource, int32, Amount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlasticDelegate_OnUpdateResourceBar, int32, CurrentAmount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDialogueDelegate_OnNotificationHappens, FString, NotificationId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDialogueDelegate_OnNotificationClosed, FString, NotificationId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlasticDelegate_OnWorkerDies, int32, WorkerId);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PLASTICCULT_API UPCEvents : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPCEvents();

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Arena Events")
	FPlasticDelegate_OnInitResourcesBar OnInitResourcesBar;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Arena Events")
	FPlasticDelegate_OnAddResource OnAddResource;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Arena Events")
	FPlasticDelegate_OnUpdateResourceBar OnUpdateResourceBar;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Arena Events")
	FDialogueDelegate_OnNotificationHappens OnNotificationHappens;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Arena Events")
	FDialogueDelegate_OnNotificationClosed OnNotificationClosed;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Worker")
	FPlasticDelegate_OnWorkerDies OnWorkerDies;
};
