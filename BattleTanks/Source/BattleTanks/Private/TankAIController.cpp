// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"


ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	APawn* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) { return nullptr; }
	return Cast<ATank>(PlayerTank);
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PossessedTank = GetControlledTank();

	if (!PossessedTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController : Not Possessing Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController : Possessed %s"), *PossessedTank->GetName());
	}

	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not Player Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank Found %s"), *PlayerTank->GetName());
	}
}

