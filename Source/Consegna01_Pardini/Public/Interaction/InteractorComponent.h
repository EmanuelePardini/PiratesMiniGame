// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractorComponent.generated.h"


UCLASS( ClassGroup=(Interaction), meta=(BlueprintSpawnableComponent) )
class CONSEGNA01_PARDINI_API UInteractorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractorComponent();
	
protected:
	UPROPERTY(EditAnywhere)
	float InteractionDistance = 100;
	UPROPERTY(EditAnywhere)
	FName InteractionMask = "OverlapAllDynamic"; //By Default, Actually overwritten with Custom "Interaction"
	UPROPERTY(EditAnywhere)
	float Radius = 60;
	
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Interact();
};
