// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PCGameInstance.generated.h"

class UPCEvents;

UCLASS()
class PLASTICCULT_API UPCGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPCGameInstance();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Global Events")
	UPCEvents* PCEvents;
};
