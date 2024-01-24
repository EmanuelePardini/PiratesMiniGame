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
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TMap<TSubclassOf<UInventoryItem>, UInventorySlot*> InventoryMap;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<UInventorySlot*> InventoryArray;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Setup")
	int InventoryLength = 5;
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
	bool AddItem(AItem* Item);
	UFUNCTION(BlueprintCallable)
	bool MoveItem(UInventorySlot* Slot);
	UFUNCTION(BlueprintCallable)
	bool MoveAll(UInventoryComponent* NewInventory);
	UFUNCTION(BlueprintCallable)
	bool DropItem(bool RemoveHalf = false);

};
