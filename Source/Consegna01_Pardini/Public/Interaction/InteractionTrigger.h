// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Interactable.h"
#include "InteractionTrigger.generated.h"

/**
 * 
 */
UCLASS()
class CONSEGNA01_PARDINI_API AInteractionTrigger : public AInteractable
{
	//That trigger interactions without any input
	GENERATED_BODY()

public:
	AInteractionTrigger();

protected:
	UPROPERTY(EditAnywhere)
	USphereComponent* Collider;
	UPROPERTY(EditAnywhere, Category="Setup")
	bool SwitchOn = false;
	UPROPERTY(EditAnywhere, Category="Setup")
	TArray<AInteractable*> LinkedInteractables;
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION()
	void OnEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};