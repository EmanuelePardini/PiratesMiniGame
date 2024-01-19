// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "Anim/PirateAnim.h"
#include "GameFramework/Character.h"
#include "PirateCharacter.generated.h"

UCLASS()
class CONSEGNA01_PARDINI_API APirateCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APirateCharacter();

protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	class UCameraComponent* ThirdPersonCamera;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	class UCameraComponent* FirstPersonCamera;
	UPROPERTY(VisibleAnywhere)
	bool FirstPersonActive = false;
	UPROPERTY(EditAnywhere)
	UPirateAnim* Animations;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Primary Actions
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	//Run Manage
	void Run(const FInputActionValue& Value);
	void EndRun(const FInputActionValue& Value);

	//Interaction Manage
	void Interact(const FInputActionValue& Value);

	//Drop Items Manage
	void Drop(const FInputActionValue& Value);

	//Change Visual Manage
	void ChangeVisual(const FInputActionValue& Value);

	//Manage Animations
	void Animate();

};