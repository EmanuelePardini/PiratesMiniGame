// Fill out your copyright notice in the Description page of Project Settings.


	#include "Characters/PiratesPlayerController.h"

#include "EngineUtils.h"
#include "EnhancedInputComponent.h"
#include "Characters/PlayerInputData.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerStart.h"

void APiratesPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//Add Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(CharacterMappingContext, 0);
	}
	
	SpawnPlayer();
}

void APiratesPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	ManageTimers(DeltaSeconds);
}

void APiratesPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if(UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		//Moving
		EnhancedInputComponent->BindAction(InputData->Move, ETriggerEvent::Triggered, this, &APiratesPlayerController::Move);

		//Looking
		EnhancedInputComponent->BindAction(InputData->Look, ETriggerEvent::Triggered, this, &APiratesPlayerController::Look);
		
		//Jumping
		EnhancedInputComponent->BindAction(InputData->Jump, ETriggerEvent::Triggered, this, &APiratesPlayerController::Jump);
		
		//Interacting
		EnhancedInputComponent->BindAction(InputData->Interact, ETriggerEvent::Triggered, this, &APiratesPlayerController::Interact);
		EnhancedInputComponent->BindAction(InputData->Drop, ETriggerEvent::Triggered, this, &APiratesPlayerController::Drop);
		EnhancedInputComponent->BindAction(InputData->DropHalf, ETriggerEvent::Triggered, this, &APiratesPlayerController::DropHalf);

		//Change Visual and Character
		EnhancedInputComponent->BindAction(InputData->ChangeCharacter, ETriggerEvent::Triggered, this, &APiratesPlayerController::ChangeCharacter);
		EnhancedInputComponent->BindAction(InputData->ChangeVisual, ETriggerEvent::Triggered, this, &APiratesPlayerController::ChangeVisual);

		//Running
		EnhancedInputComponent->BindAction(InputData->Run, ETriggerEvent::Triggered, this, &APiratesPlayerController::Run);
		EnhancedInputComponent->BindAction(InputData->Run, ETriggerEvent::Completed, this, &APiratesPlayerController::EndRun);
	}
	
}

void APiratesPlayerController::SpawnPlayer()
{
	uint8 RosterLenght = CharacterRoster->Characters.Num();
	UWorld* World = GetWorld();
	
	//For any character spawn the pirate from the character roster at the player start selected in the gamemode
	for ( PirateIndex = 0; PirateIndex <= RosterLenght-1; PirateIndex++)
	{
		//Select the pirate to spawn
		SelectedCharacter = CharacterRoster->Characters[PirateIndex];

		//Spawn the Character and save in a variable
		APirateCharacter* PirateCharacter = World->SpawnActor<APirateCharacter>(
				SelectedCharacter.Pirate,
				FindPlayerStart(SelectedCharacter)->GetActorLocation(),
				FindPlayerStart(SelectedCharacter)->GetActorRotation(),
				FActorSpawnParameters());

		//Add the characters variable to the available characters array
		PirateCharacters.Add(PirateCharacter);
		
	}

	PirateIndex = 0;
	Possess(PirateCharacters[0]);
}

APlayerStart* APiratesPlayerController::FindPlayerStart(FCharacterData CharacterData)
{
	//Iterate all the player start to find the corret tag
	for (TActorIterator<APlayerStart> It(GetWorld()); It; ++It)
	{
		APlayerStart* CurrentPlayerStart = *It;

		//Check if the actual Player start match with the player start setupped in the CharacterRoster Data
		if (CurrentPlayerStart && CurrentPlayerStart->PlayerStartTag == SelectedCharacter.PlayerStartTag)
		{
			//return the matching player start
			return CurrentPlayerStart;
		}
	}
	//else return new player start
	APlayerStart* NewPlayerStart = GetWorld()->SpawnActor<APlayerStart>(APlayerStart::StaticClass(), FVector(0, 0, 0), FRotator::ZeroRotator, FActorSpawnParameters());
	return NewPlayerStart;
}

void APiratesPlayerController::ManageTimers(float DeltaSeconds)
{
	ChangeTimer += DeltaSeconds;
	InteractTimer += DeltaSeconds;

	if(ChangeTimer >= ChangeDelay)
	{
		CanChange = true;
	}
	if(InteractTimer >= ChangeDelay)
	{
		CanInteract = true;
	}
}


void APiratesPlayerController::Move(const FInputActionValue& Value)
{
	if(PirateCharacters[PirateIndex])
	{
		PirateCharacters[PirateIndex]->Move(Value);
	}
}

void APiratesPlayerController::Look(const FInputActionValue& Value)
{
	if(PirateCharacters[PirateIndex])
	{
		PirateCharacters[PirateIndex]->Look(Value);
	}
}

void APiratesPlayerController::Jump(const FInputActionValue& Value)
{
	if(PirateCharacters[PirateIndex])
	{
		PirateCharacters[PirateIndex]->Jump();
		ChangeTimer = 0;
		CanChange = false;
	}
}

void APiratesPlayerController::Run(const FInputActionValue& Value)
{
	if(PirateCharacters[PirateIndex])
	{
		PirateCharacters[PirateIndex]->Run(Value);
	}
}

void APiratesPlayerController::EndRun(const FInputActionValue& Value)
{
	if(PirateCharacters[PirateIndex])
	{
		PirateCharacters[PirateIndex]->EndRun(Value);
	}
}

void APiratesPlayerController::Interact(const FInputActionValue& Value)
{
	if(PirateCharacters[PirateIndex] && CanInteract)
	{
		PirateCharacters[PirateIndex]->Interact(Value);

		InteractTimer = 0;
		CanInteract = false;
	}
}

void APiratesPlayerController::Drop(const FInputActionValue& Value)
{
	if(PirateCharacters[PirateIndex] && CanInteract)
	{
		PirateCharacters[PirateIndex]->Drop(Value);

		InteractTimer = 0;
		CanInteract = false;
	}
}

void APiratesPlayerController::DropHalf(const FInputActionValue& Value)
{
	if(PirateCharacters[PirateIndex] && CanInteract)
	{
		PirateCharacters[PirateIndex]->DropHalf(Value);

		InteractTimer = 0;
		CanInteract = false;
	}
}

void APiratesPlayerController::ChangeVisual(const FInputActionValue& Value)
{
	if(PirateCharacters[PirateIndex] && CanChange)
	{
		PirateCharacters[PirateIndex]->ChangeVisual(Value);

		ChangeTimer = 0;
		CanChange = false;
	}
}

//Change Character is a duty of the controller so implemented here
void APiratesPlayerController::ChangeCharacter(const FInputActionValue& Value)
{
	//If the actual Character is falling can't change
	APirateCharacter* ActualPirate = PirateCharacters[PirateIndex];
	bool IsFalling = ActualPirate->GetCharacterMovement()->IsFalling();
	
	
	if((CanChange && !IsFalling) || ActualPirate == nullptr) //Don't need Character check in case the actual character died
	{
		//If it isn't the last character of the roster go to the next
		if(PirateIndex < PirateCharacters.Num()-1)
		{
			PirateIndex+=1;
		}
		else //else if is the last restart 
		{
			PirateIndex = 0;
		}
		
		APirateCharacter* NextPirate = PirateCharacters[PirateIndex];

		//Manage the animations and possess the character
		ActualPirate->Animations->StopAnimate(ActualPirate);
		NextPirate->Animations->StartAnimate(NextPirate);
		Possess(NextPirate);

		ChangeTimer = 0;
		CanChange = false;
	}
}
