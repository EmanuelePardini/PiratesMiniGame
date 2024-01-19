// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ContentBrowserDataSource.h"
#include "UObject/NoExportTypes.h"
#include "InventoryItem.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class CONSEGNA01_PARDINI_API UInventoryItem : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Item")
	FString Name;
	UPROPERTY(EditAnywhere, Category="Item")
	FString Category;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ToSpawn;

public:
	FORCEINLINE FString GetItemName() const{return Name;}
	FORCEINLINE FString GetItemCategory() const{return Category;}
	FORCEINLINE TSubclassOf<AActor> GetActorToSpawn() const{ return ToSpawn;}
};
