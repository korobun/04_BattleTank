// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "Engine/World.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;	

private:
	ATank* GetControlledTank() const;
	//этот метод начинает двигать ствол туда
	//где перекрестье прицела пересекает мир
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation);

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;

	UPROPERTY(EditAnywhere)
	float TargetHitLength = 1000000.f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& WorldDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation);
};
