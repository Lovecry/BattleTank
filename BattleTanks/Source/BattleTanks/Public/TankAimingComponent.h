// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"

#include "Kismet/GameplayStatics.h"
#include "Engine.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked,
	OutOfAmmo
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	virtual void BeginPlay() override;

	void AimAt(FVector);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	UFUNCTION(BlueprintCallable, Category = "Firing")
	int32 GetRoundsLeft() const { return RoundsLeft; };

	EFiringState GetFiringState() const;

protected:

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;
	
private:

	UTankAimingComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void MoveBarrelTowards(FVector AimDirection);
	bool IsBarrelMoving();

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000.0f;

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	uint32 RoundsLeft = 3;

	double LastFireTime = 0;
	FVector AimingDirection;

};
