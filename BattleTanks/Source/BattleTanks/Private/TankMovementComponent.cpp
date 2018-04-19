// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankMovementComponent.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;

}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward Throw : %f"), Throw);
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendMoveBackward(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward Throw : %f"), Throw);
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward Throw : %f"), Throw);
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::IntendTurnLeft(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward Throw : %f"), Throw);
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(Throw);
}