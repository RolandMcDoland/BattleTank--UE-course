// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Get possesed tank
	auto ControlledTank = Cast<ATank>(GetPawn());

	//Get player tank
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		auto PlayerTank = nullptr;
	}

	auto PlayerTank = Cast<ATank>(PlayerPawn);

	if (!ControlledTank)
	{
		return;
	}

	if (PlayerTank)
	{
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->Fire();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player not found"));
	}
}


