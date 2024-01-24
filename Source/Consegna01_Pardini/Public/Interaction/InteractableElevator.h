// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "InteractableElevator.generated.h"

/**
 * 
 */
UCLASS()
class CONSEGNA01_PARDINI_API AInteractableElevator : public AInteractable
{
	GENERATED_BODY()
	
public:
	AInteractableElevator();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool CanMove = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector StartLocation;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector CurrentLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Setup")
	FVector MoveSpeed = FVector(0,0,0);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Setup")
	float Distance = 0;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Activate(ACharacter* Interactor = nullptr) override;
	virtual void Deactivate() override;
	UFUNCTION(BlueprintCallable)
	void Move();
};
