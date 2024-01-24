// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Interactable.h"
#include "InteractionCatalyst.generated.h"

/**
 * 
 */
UCLASS()
class CONSEGNA01_PARDINI_API AInteractionCatalyst : public AInteractable
{
	//That trigger interactions without any input
	GENERATED_BODY()

public:
	AInteractionCatalyst();

protected:
	UPROPERTY(EditAnywhere, Category="Setup")
	USphereComponent* Collider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Setup")
	bool SwitchOn = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Setup")
	TArray<AInteractable*> LinkedInteractables;

	UFUNCTION(Blueprintable)
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION(Blueprintable)
	void OnEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
