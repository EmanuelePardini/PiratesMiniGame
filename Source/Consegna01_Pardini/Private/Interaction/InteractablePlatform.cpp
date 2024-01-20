// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/InteractablePlatform.h"

AInteractablePlatform::AInteractablePlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	
	NeedInput = false;
}

void AInteractablePlatform::BeginPlay()
{
	Super::BeginPlay();
	startPosition = GetActorLocation();
}

void AInteractablePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(CanMove)
	{
		Move();
	}
}

void AInteractablePlatform::Activate()
{
	Super::Activate();
	CanMove = true;
}

void AInteractablePlatform::Deactivate()
{
	Super::Deactivate();
	CanMove = false;
}

void AInteractablePlatform::Move()
{
	currentPosition = GetActorLocation();
	currentPosition = currentPosition + (platSpeed);
	SetActorLocation(currentPosition);
    
	float distanceMove = FVector::Dist(startPosition, currentPosition);
    
	if (distanceMove > Distance)
	{
		FVector moveDirection = platSpeed.GetSafeNormal();
		startPosition = startPosition + (distanceMove * moveDirection);
		SetActorLocation(startPosition);
		platSpeed = -platSpeed;
	}
}
