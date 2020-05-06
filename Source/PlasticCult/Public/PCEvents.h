// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PCEvents.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlasticDelegate_OnAddResource, int32, Amount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDialogueDelegate_OnNotificationHappens, FString, NotificationId);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PLASTICCULT_API UPCEvents : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPCEvents();

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Arena Events")
	FPlasticDelegate_OnAddResource OnAddResource;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Arena Events")
	FDialogueDelegate_OnNotificationHappens OnNotificationHappens;
};
