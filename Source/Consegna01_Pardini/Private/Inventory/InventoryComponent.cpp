// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

//TODO: Review and optimize InventoryComponent functions( NonStackable Items, Drop the right item)
void UInventoryComponent::AddItem(AItem* Item)
{
	//If the Item is already contained 
	bool Contained = InventoryMap.Contains(Item->GetItemData());
	//and is stackable
	bool IsStackable = Item->GetIsStackable();

	//then the Item is to stack
	if(Contained && IsStackable)
	{
		InventoryMap[Item->GetItemData()]->Quantity += Item->GetQuantity();
	}
	else //Else add a slot and Insert Item in a new slot
	{
		UInventorySlot* Slot = NewObject<UInventorySlot>();
		Slot->Init(Item->GetQuantity(), Item->GetItemData());
		InventoryMap.Add(Item->GetItemData(), Slot);
		InventoryArray.Add(Slot);
		
	}

	//Destroy InScene Item
	Item->Destroy();
}

bool UInventoryComponent::DropItem()
{
	//If Inventory is Empty do nothing
	if(InventoryMap.IsEmpty()) return false;

		//Find the last item of the inventory
		UInventorySlot* LastSlot = InventoryArray.Last();
		TSubclassOf<UInventoryItem> ItemType = LastSlot->GetItemType();
		
		//Get the information to spawn the Item InScene
		const FVector Position = FVector(GetOwner()->GetActorLocation().X+100,GetOwner()->GetActorLocation().Y,GetOwner()->GetActorLocation().Z);
		const FRotator Rotation = GetOwner()->GetActorRotation();
		
		//Spawn the Item
		GetWorld()->SpawnActor(LastSlot->GetInventoryItem()->GetItemToSpawn(), &Position, &Rotation);
		
		//Remove it from the collections
		InventoryMap.Remove(ItemType);
		InventoryArray.Remove(LastSlot);

		return true;

}

