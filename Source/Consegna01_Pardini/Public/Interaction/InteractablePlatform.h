// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "InteractablePlatform.generated.h"

/**
 * 
 */
UCLASS()
class CONSEGNA01_PARDINI_API AInteractablePlatform : public AInteractable
{
	GENERATED_BODY()
	
public:
	AInteractablePlatform();

protected:
	UPROPERTY(VisibleAnywhere)
	bool CanMove = false;
	UPROPERTY(VisibleAnywhere)
	FVector startPosition;
	UPROPERTY(EditAnywhere)
	FVector currentPosition;
	UPROPERTY(EditAnywhere)
	FVector platSpeed = FVector(0,0,0);
	UPROPERTY(EditAnywhere)
	float Distance = 0;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Activate() override;
	virtual void Deactivate() override;
	UFUNCTION()
	void Move();
};
