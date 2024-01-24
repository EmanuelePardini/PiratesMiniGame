// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "Anim/PirateAnim.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Interaction/InteractorComponent.h"
#include "Inventory/InventoryComponent.h"
#include "PirateCharacter.generated.h"

UCLASS()
class CONSEGNA01_PARDINI_API APirateCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APirateCharacter();
	
	//Component Declaration
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UInteractorComponent* InteractorComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UInventoryComponent* InventoryComponent;

	//Anim Instances Declaration
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animations")
	UPirateAnim* Animations;

protected:
	//Camera Declaration
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category="Camera")
	USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category="Camera")
	UCameraComponent* ThirdPersonCamera;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category="Camera")
	UCameraComponent* FirstPersonCamera;
	UPROPERTY(VisibleAnywhere, Category="Camera")
	bool FirstPersonActive = false;
	
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
	void DropHalf(const FInputActionValue& Value);

	//Change Visual Manage
	void ChangeVisual(const FInputActionValue& Value);

};
