// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/Item.h"
#include "Inventory/InventoryComponent.h"

void AItem::Activate(AActor* Actor)
{
	//Add Item to the Inventory
	UInventoryComponent* Inventory = Actor->GetComponentByClass<UInventoryComponent>();
	Inventory->AddItem(this);

	//Destroy InScene Actor
	Destroy();

	Super::Activate();
}
