// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankTurret.h"


void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);
	auto RotationChange = RelativeSpeed * MaxDegreePerSecnd * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0.0f, RawNewRotation, 0.0f));
}

