// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "InventoryItem.h"
#include "Item.generated.h"

/**
 * 
 */
UCLASS()
class CONSEGNA01_PARDINI_API AItem : public AInteractable
{
	GENERATED_BODY()

public:
	AItem();

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UInventoryItem> ItemData;
	UPROPERTY(EditAnywhere)
	uint8 Quantity;
	
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaSeconds) override;
};
