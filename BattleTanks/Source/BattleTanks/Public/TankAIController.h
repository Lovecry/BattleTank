// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"

#include "Engine/World.h"
#include "AIController.h"
#include "CoreMinimal.h"
#include "TankAIController.generated.h"

UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()	

private:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	float AcceptanceRadius = 300.f;
};
