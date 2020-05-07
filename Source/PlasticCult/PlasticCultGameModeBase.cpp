// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "PlasticCultGameModeBase.h"
#include "Public/PCPawn.h"
#include "Public/PCPlayerController.h"

APlasticCultGameModeBase::APlasticCultGameModeBase()
{
	// no pawn by default
	DefaultPawnClass = APCPawn::StaticClass();
	// use our own player controller class
	PlayerControllerClass = APCPlayerController::StaticClass();
}
