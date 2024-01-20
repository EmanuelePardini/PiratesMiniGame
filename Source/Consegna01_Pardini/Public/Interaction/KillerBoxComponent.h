// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "KillerBoxComponent.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent))
class CONSEGNA01_PARDINI_API UKillerBoxComponent : public UBoxComponent
{
	//When Player Collides to an actor with this component die
	GENERATED_BODY()
public:
	UKillerBoxComponent();
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
	void Kill(ACharacter* Character);
	
};
