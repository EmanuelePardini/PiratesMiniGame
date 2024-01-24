// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Interaction/Interactable.h"
#include "InteractableMissionBox.generated.h"

/**
 * 
 */
UCLASS()
class CONSEGNA01_PARDINI_API AInteractableMissionBox : public AInteractable
{
	GENERATED_BODY()
public:
	AInteractableMissionBox();

protected:
	UPROPERTY(EditAnywhere)
	UBoxComponent* Collider;
	UPROPERTY(EditAnywhere, Category="Setup")
	FText NextMission;

public:
	UFUNCTION(Blueprintable)
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	virtual void Activate(ACharacter* Interactor = nullptr) override;
};
