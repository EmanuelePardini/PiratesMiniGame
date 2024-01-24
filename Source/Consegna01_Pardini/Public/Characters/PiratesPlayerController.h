// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterData.h"
#include "Characters/CharacterRoster.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "PiratesPlayerController.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class CONSEGNA01_PARDINI_API APiratesPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	//For Inputs
	UPROPERTY(EditAnywhere)
	class UPlayerInputData* InputData;
	UPROPERTY(EditAnywhere)
	class UInputMappingContext* CharacterMappingContext;
	
	//For Pirate Control
	UPROPERTY(VisibleAnywhere)
	TArray<APirateCharacter*> PirateCharacters;
	UPROPERTY(VisibleAnywhere)
	uint8 PirateIndex;
	
	//CharacterRoster Management
	UPROPERTY(EditAnywhere)
	UCharacterRoster* CharacterRoster;
	UPROPERTY(EditAnywhere)
	FCharacterData SelectedCharacter;

	//To Manage Actions Timer and avoid Spam
	UPROPERTY(EditAnywhere)
	bool CanChange;
	UPROPERTY(EditAnywhere)
	float ChangeTimer = 0;
	UPROPERTY(EditAnywhere)
	float ChangeDelay = 0.5;
	UPROPERTY(EditAnywhere)
	bool CanInteract;
	UPROPERTY(EditAnywhere)
	float InteractTimer = 0;
	UPROPERTY(EditAnywhere)
	float InteractDelay = 0.5;

private:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupInputComponent() override;
	
	//Spawn Player
	void SpawnPlayer();
	APlayerStart* FindPlayerStart(FCharacterData CharacterData);

	//For Timers Management
	void ManageTimers(float DeltaSeconds);
	
	//Primary Actions
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	//Jump Manage
	void Jump(const FInputActionValue& Value);

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

	//Change Character Manage(Controller Responsibility)
	void ChangeCharacter(const FInputActionValue& Value);
	
};
