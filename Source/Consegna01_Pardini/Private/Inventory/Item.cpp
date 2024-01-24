// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/Item.h"
#include "GameFramework/Character.h"
#include "Inventory/InventoryComponent.h"



void AItem::Activate(ACharacter* Interactor)
{
	Super::Activate(Interactor);
	UInventoryComponent* Inventory = Interactor->GetComponentByClass<UInventoryComponent>();
	Inventory->AddItem(this);
}
