// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "InteractableSwitch.generated.h"

/**
 * 
 */
UCLASS()
class CONSEGNA01_PARDINI_API AInteractableSwitch : public AInteractable
{
	//A Type of Interactable that can have 2 location and rotation states
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category="Setup")
	bool SwitchOn = false;
	UPROPERTY(EditAnywhere, Category="Setup")
	TArray<AInteractable*> LinkedInteractables;
	UPROPERTY(EditAnywhere, Category="Setup")
	FRotator SwitchRotation = FRotator(0,0,0);
	UPROPERTY(EditAnywhere, Category="Setup")
	FVector SwitchLocation = FVector(0,0,0);

protected:
	virtual void Activate() override;
};
