// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
#include "InventorySlot.h"
#include "Item.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Inventory), meta=(BlueprintSpawnableComponent))
class CONSEGNA01_PARDINI_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();
	
protected:
	UPROPERTY(EditAnywhere)
	TMap<TSubclassOf<UInventoryItem>, UInventorySlot*> InventoryMap;
	UPROPERTY(EditAnywhere)
	TArray<UInventorySlot*> InventoryArray;
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
	void AddItem(AItem* Item);
	UFUNCTION(BlueprintCallable)
	bool DropItem();
};
