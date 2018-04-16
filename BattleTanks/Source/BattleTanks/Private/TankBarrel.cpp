// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);
	auto ElevationChange = RelativeSpeed * MaxDegreePerSecnd * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	RawNewElevation = FMath::Clamp(RawNewElevation, MinElevationDegree, MaxElevationDegree);

	SetRelativeRotation(FRotator(RawNewElevation, 0.0f, 0.0f));
}
