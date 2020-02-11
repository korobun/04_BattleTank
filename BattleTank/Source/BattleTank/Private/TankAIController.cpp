// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	if (GetPlayerTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller find %s"), *GetPlayerTank()->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller not find PlayerTank"), *GetPlayerTank()->GetName())
	};
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{		
		GetControlledTank()->AimAt(GetPlayerTank()->GetTargetLocation());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{	
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
