// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (GetTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("Controlling pawn is %s"), *GetTank()->GetName())
	};
}

ATank* ATankPlayerController::GetTank() const
{
	return Cast<ATank>(GetPawn());
}

