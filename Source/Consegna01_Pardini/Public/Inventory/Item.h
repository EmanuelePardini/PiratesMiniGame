// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
#include "Interaction/Interactable.h"
#include "Item.generated.h"

/**
 * 
 */
UCLASS()
class CONSEGNA01_PARDINI_API AItem : public AInteractable
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UInventoryItem> ItemData = UInventoryItem::StaticClass();
	UPROPERTY(EditAnywhere)
	bool IsStackable = true;
	UPROPERTY(EditAnywhere)
	uint8 Quantity = 1;

public:
	FORCEINLINE TSubclassOf<UInventoryItem> GetItemData() const {return ItemData;}
	FORCEINLINE bool GetIsStackable() const {return IsStackable;}
	FORCEINLINE int GetQuantity() const {return Quantity;}
	
	virtual void Activate(AActor* Actor);
};
