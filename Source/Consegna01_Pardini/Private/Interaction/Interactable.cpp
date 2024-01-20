// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/Interactable.h"

// Sets default values
AInteractable::AInteractable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInteractable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	InteractionTimer += DeltaTime;

	if(InteractionTimer >= InteractionDelay)
	{
		CanActivate = true;
	}
}

void AInteractable::Activate()
{
	CanActivate = false;
	InteractionTimer = 0;
}

void AInteractable::Deactivate()
{
}



