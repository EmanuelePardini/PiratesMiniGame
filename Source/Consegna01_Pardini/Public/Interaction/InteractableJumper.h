// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Interactable.h"
#include "InteractableJumper.generated.h"

/**
 * 
 */
UCLASS()
class CONSEGNA01_PARDINI_API AInteractableJumper : public AInteractable
{
	GENERATED_BODY()
public:
	AInteractableJumper();

protected:
	UPROPERTY(EditAnywhere)
	USphereComponent* Collider;
	UPROPERTY(EditAnywhere)
	float InitialJumpSpeed;
	UPROPERTY(EditAnywhere)
	float JumpSpeed = 2100;
	UPROPERTY()
	ACharacter* Interactor;

public:
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION()
	void OnEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	virtual void Activate() override;
	virtual void Deactivate() override;
};
