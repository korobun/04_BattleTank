// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void ElevateBarrel(float);

private:
	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxDegrPerSecond = 20.f;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxElevationDegr = 40.f;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float MinElevationDegr = 0.f;

};
