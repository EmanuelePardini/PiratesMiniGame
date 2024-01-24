// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/InteractableElevator.h"

AInteractableElevator::AInteractableElevator()
{
	PrimaryActorTick.bCanEverTick = true;
	
	NeedInput = false;
}

void AInteractableElevator::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

void AInteractableElevator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(CanMove)
	{
		Move();
	}
}

void AInteractableElevator::Activate(ACharacter* Interactor)
{
	Super::Activate(Interactor);
	CanMove = true;
}

void AInteractableElevator::Deactivate()
{
	Super::Deactivate();
	CanMove = false;
}

void AInteractableElevator::Move()
{
	//Get position to continue by that
	CurrentLocation = GetActorLocation();
	//Add the plat speed vector and refresh the location
	CurrentLocation = CurrentLocation + (MoveSpeed);
	SetActorLocation(CurrentLocation);

	//Calculate distance by the start
	float distanceMove = FVector::Dist(StartLocation, CurrentLocation);

	//If arrived invert the direction
	if (distanceMove > Distance)
	{
		FVector moveDirection = MoveSpeed.GetSafeNormal();
		StartLocation = StartLocation + (distanceMove * moveDirection);
		SetActorLocation(StartLocation);
		MoveSpeed = -MoveSpeed;
	}
}
