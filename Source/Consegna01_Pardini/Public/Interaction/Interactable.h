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
	UPROPERTY(VisibleAnywhere)
	bool NeedInput = true; //Needs Input by default
	
	// Sets default values for this actor's properties
	AInteractable();

protected:
	//Variables to avoid Spam
	UPROPERTY(VisibleAnywhere)
	bool CanActivate = false; 
	UPROPERTY(VisibleAnywhere)
	float InteractionTimer = 0;
	UPROPERTY(EditAnywhere)
	float InteractionDelay = 1;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Activate();
	virtual void Deactivate();


};
