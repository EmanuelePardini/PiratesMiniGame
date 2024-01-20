// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/InteractableSwitch.h"

void AInteractableSwitch::Activate()
{
	if(CanActivate)
	{
		FRotator ActualRotation = GetActorRotation();
		FVector ActualLocation= GetActorLocation();
	
		//If on turn it off
		if(SwitchOn)
		{
			SwitchOn = false;
			SetActorRotation(ActualRotation + SwitchRotation);
			SetActorLocation(ActualLocation + SwitchLocation);

		}
		//else turn it on
		else
		{
			SwitchOn = true;
			SetActorRotation(ActualRotation - SwitchRotation);
			SetActorLocation(ActualLocation - SwitchLocation);
		}
		
		//Change status to all the linked interactables
		for (auto const LinkedInteractable : LinkedInteractables)
		{
			LinkedInteractable->Activate();
		}
	}
	//The father istruction needs to be executed lasts
	Super::Activate();

}

