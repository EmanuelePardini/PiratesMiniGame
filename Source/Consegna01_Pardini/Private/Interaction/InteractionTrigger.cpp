// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/InteractionTrigger.h"

#include "GameFramework/Character.h"

AInteractionTrigger::AInteractionTrigger()
{
	//Setup Collider
	Collider = CreateDefaultSubobject<USphereComponent>("Collider");
	Collider->SetupAttachment(RootComponent);
	Collider->OnComponentBeginOverlap.AddDynamic(this, &AInteractionTrigger::OnOverlapBegin);
	Collider->OnComponentEndOverlap.AddDynamic(this, &AInteractionTrigger::OnEndOverlap);
}

void AInteractionTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Check if is a Character
	ACharacter* Character = Cast<ACharacter>(OtherActor);
	if(Character)
	{
		//If is a character activate all the linked interactables that don't needs input
		for(AInteractable* Interactable : LinkedInteractables)
		{
			
			if(!Interactable->NeedInput) Interactable->Activate();
		}
	}
}

void AInteractionTrigger::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ACharacter* Character = Cast<ACharacter>(OtherActor);
	if(Character)
	{
		//If is a character deactivate all the linked interactables that don't needs input
		for(AInteractable* Interactable : LinkedInteractables)
		{
			if(!Interactable->NeedInput) Interactable->Deactivate();
		}
	}
}
