// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interaction/Interactable.h"
#include "Inventory/InventoryComponent.h"
#include "InteractableChest.generated.h"

/**
 * 
 */
UCLASS()
class CONSEGNA01_PARDINI_API AInteractableChest : public AInteractable
{
	GENERATED_BODY()
public:
	AInteractableChest();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UInventoryComponent* InventoryComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Setup")
	TArray<AItem*> ContainedItems;

	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	void FillChest();
	virtual void Activate(ACharacter* Interactor) override;	
};
