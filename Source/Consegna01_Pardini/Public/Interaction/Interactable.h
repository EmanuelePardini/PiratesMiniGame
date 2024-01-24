// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

UCLASS()
class CONSEGNA01_PARDINI_API AInteractable : public AActor
{
	GENERATED_BODY()
	
public:
	//To check if need the input of the player to start interaction
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Setup")
	bool NeedInput = true; //Needs Input by default
	
	// Called every frame
	UFUNCTION(BlueprintCallable)
	virtual void Activate(ACharacter* Interactor = nullptr);
	UFUNCTION(BlueprintCallable)
	virtual void Deactivate();

};
