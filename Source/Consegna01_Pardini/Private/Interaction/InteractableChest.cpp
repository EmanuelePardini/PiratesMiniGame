// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/InteractableChest.h"
#include "Characters/PirateCharacter.h"

AInteractableChest::AInteractableChest()
{
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>("ChestInventory");
}

void AInteractableChest::BeginPlay()
{
	Super::BeginPlay();
	
	FillChest();
}

void AInteractableChest::FillChest()
{
	//Insert into the Chest the selected Items
	for(auto Item : ContainedItems)
	{
		InventoryComponent->AddItem(Item);
	}
}

void AInteractableChest::Activate(ACharacter* Interactor)
{
	Super::Activate(Interactor);
	APirateCharacter* Character = Cast<APirateCharacter>(Interactor);
	InventoryComponent->MoveAll(Character->InventoryComponent);
}

