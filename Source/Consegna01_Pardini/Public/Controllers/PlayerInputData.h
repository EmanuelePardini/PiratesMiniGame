// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PlayerInputData.generated.h"

/**
 * 
 */
UCLASS()
class CONSEGNA01_PARDINI_API UPlayerInputData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly)
	FString MappingName;
	UPROPERTY(EditDefaultsOnly)
	class UInputAction* Move;
	UPROPERTY(EditDefaultsOnly)
	UInputAction* Look;
	UPROPERTY(EditDefaultsOnly)
	UInputAction* Jump;
	UPROPERTY(EditDefaultsOnly)
	UInputAction* Run;
	UPROPERTY(EditDefaultsOnly)
	UInputAction* Interact;
	UPROPERTY(EditDefaultsOnly)
	UInputAction* Drop;
	UPROPERTY(EditDefaultsOnly)
	UInputAction* ChangeCharacter;
	UPROPERTY(EditDefaultsOnly)
	UInputAction* ChangeVisual;
};
