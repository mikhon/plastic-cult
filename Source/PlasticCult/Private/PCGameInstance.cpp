// Fill out your copyright notice in the Description page of Project Settings.

#include "PCGameInstance.h"
#include "PCEvents.h"

UPCGameInstance::UPCGameInstance()
{
	PCEvents = CreateDefaultSubobject<UPCEvents>(TEXT("PCEvents"));
}
