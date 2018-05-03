// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/IDamagebleActor.h"

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANKS_API ATank : public APawn , public IIDamagebleActor
{
	GENERATED_BODY()

public:
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	FTankDelegate OnDeath;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Health")
		float GetHealthPercent();
		virtual float GetHealthPercent_Implementation() override;

private:
	ATank();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	int32 StartingHealth = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Setup")
	int32 CurrentHealth = 100.0f;
};
