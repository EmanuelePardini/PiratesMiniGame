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
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool ToAnimate = true;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float SpeedX = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float SpeedY = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool Grounded = true;

public:
	void Animate(ACharacter* Character);
	FORCEINLINE void StartAnimate (ACharacter* Character) {ToAnimate = true;} 
	FORCEINLINE void StopAnimate(ACharacter* Character) {SpeedX=0; SpeedY=0; ToAnimate = false;} //Reset all the value
	FVector GetDeltaRoot(){return ConsumeExtractedRootMotion(1).GetRootMotionTransform().GetLocation();}
	
};
