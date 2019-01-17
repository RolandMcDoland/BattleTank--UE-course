// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

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

	public:
		ATank* GetControlledTank() const;

		void BeginPlay() override;
	
		void Tick(float DeltaTime) override;
	
		void AimTowardsCrosshair();

		bool GetSightRayHitLocation(FVector&) const;
};
