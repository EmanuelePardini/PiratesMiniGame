// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PirateAnim.generated.h"

/**
 * 
 */
UCLASS()
class CONSEGNA01_PARDINI_API UPirateAnim : public UAnimInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float SpeedX = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float SpeedY = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool Grounded = true;
	
	void Animate(ACharacter* Character);
	FVector GetDeltaRoot(){return ConsumeExtractedRootMotion(1).GetRootMotionTransform().GetLocation();}
	
};
