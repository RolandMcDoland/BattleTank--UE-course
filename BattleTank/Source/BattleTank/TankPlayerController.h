// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
class UWorld;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

	private:
		UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5f;

		UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.33333f;

		UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.0f;

	public:
		ATank* GetControlledTank() const;

		void BeginPlay() override;
	
		void Tick(float DeltaTime) override;
	
		void AimTowardsCrosshair();

		bool GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;

		bool GetSightRayHitLocation(FVector& HitLocation) const;
};
