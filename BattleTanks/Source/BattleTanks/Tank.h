// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	FTankDelegate OnDeath;

	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const { return (float)CurrentHealth / (float)StartingHealth; };

private:
	ATank();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100.0f;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	int32 CurrentHealth = 100.0f;
};
