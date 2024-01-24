// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/InteractableSwitch.h"

#include "GameFramework/Character.h"
#include "Inventory/InventoryComponent.h"

AInteractableSwitch::AInteractableSwitch()
{
	//If the switch has a cost initialize to locked
	if(ItemType && Cost > 0) Unlocked = false;
}

void AInteractableSwitch::Activate(ACharacter* Interactor)
{
	Super::Activate(Interactor);
	
	//If the switch is locked and has a cost
	if(!Unlocked && ItemType && Cost > 0)
	{
		UInventoryComponent* InventoryComponent = Interactor->GetComponentByClass<UInventoryComponent>();
		
		//If you have enough item to pay then unlock the switch
		if(InventoryComponent->UseItem(ItemType, Cost)) Unlocked = true;
	}
	else
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
	
}
