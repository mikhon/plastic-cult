// Fill out your copyright notice in the Description page of Project Settings.


#include "PCPawn.h"

// Sets default values
APCPawn::APCPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void APCPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APCPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APCPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APCPawn::CalcCamera(float DeltaTime, struct FMinimalViewInfo& OutResult)
{
	Super::CalcCamera(DeltaTime, OutResult);
	OutResult.Rotation = FRotator(-36.2f, 5.0f, -16.6f);
	OutResult.Location = FVector(-200.1f, -100.0f, 398.6f);
	//OutResult.DesiredFOV
}

