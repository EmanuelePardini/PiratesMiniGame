// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/PiratesPlayerController.h"
#include "EnhancedInputComponent.h"
#include "Controllers/PlayerInputData.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"

void APiratesPlayerController::BeginPlay()
{
	Super::BeginPlay();
	SpawnPlayer();
}

void APiratesPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	ChangeTimer += DeltaSeconds;

	if(ChangeTimer >= ChangeDelay)
	{
		CanChange = true;
	}
}

void APiratesPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if(UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		//Jumping
		EnhancedInputComponent->BindAction(InputData->Jump, ETriggerEvent::Triggered, this, &APiratesPlayerController::Jump);

		//Interacting
		EnhancedInputComponent->BindAction(InputData->Interact, ETriggerEvent::Triggered, this, &APiratesPlayerController::Interact);
		EnhancedInputComponent->BindAction(InputData->Drop, ETriggerEvent::Triggered, this, &APiratesPlayerController::Drop);

		//Change Visual and Character
		EnhancedInputComponent->BindAction(InputData->ChangeCharacter, ETriggerEvent::Triggered, this, &APiratesPlayerController::ChangeCharacter);
		EnhancedInputComponent->BindAction(InputData->ChangeVisual, ETriggerEvent::Triggered, this, &APiratesPlayerController::ChangeVisual);

		//Running
		EnhancedInputComponent->BindAction(InputData->Run, ETriggerEvent::Triggered, this, &APiratesPlayerController::Run);
		EnhancedInputComponent->BindAction(InputData->Run, ETriggerEvent::Completed, this, &APiratesPlayerController::EndRun);

		//Moving
		EnhancedInputComponent->BindAction(InputData->Move, ETriggerEvent::Triggered, this, &APiratesPlayerController::Move);

		//Looking
		EnhancedInputComponent->BindAction(InputData->Look, ETriggerEvent::Triggered, this, &APiratesPlayerController::Look);
	
	}
	
}


void APiratesPlayerController::SpawnPlayer()
{
	
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(CharacterMappingContext, 0);
	}

	for ( PirateIndex = 0; PirateIndex <= CharacterRoster->Characters.Num()-1; PirateIndex++)
	{
		SelectedCharacter = CharacterRoster->Characters[PirateIndex];
		
		PirateCharacters.Add(GetWorld()->SpawnActor<APirateCharacter>(
		SelectedCharacter.Pirate,
		//TODO: GameMode in C++ and set Player Start in that
FVector(UGameplayStatics::GetActorOfClass(GetWorld(), APlayerStart::StaticClass())->GetActorLocation()),
FRotator(UGameplayStatics::GetActorOfClass(GetWorld(), APlayerStart::StaticClass())->GetActorRotation()),
		FActorSpawnParameters()));
	}

	PirateIndex = 0;
	Possess(PirateCharacters[0]);
	
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
	if(PirateCharacters[PirateIndex])
	{
		PirateCharacters[PirateIndex]->Interact(Value);
	}
}

void APiratesPlayerController::Drop(const FInputActionValue& Value)
{
	if(PirateCharacters[PirateIndex])
	{
		PirateCharacters[PirateIndex]->Drop(Value);
	}
}

void APiratesPlayerController::ChangeVisual(const FInputActionValue& Value)
{
	if(PirateCharacters[PirateIndex]&& CanChange)
	{
		PirateCharacters[PirateIndex]->ChangeVisual(Value);

		ChangeTimer = 0;
		CanChange = false;
	}
}

void APiratesPlayerController::ChangeCharacter(const FInputActionValue& Value)
{
	if(CanChange)
	{
		if(PirateIndex < PirateCharacters.Num()-1)
		{
			PirateIndex+=1;
		}
		else
		{
			PirateIndex = 0;
		}
		
		ChangeTimer = 0;
		CanChange = false;
		Possess(PirateCharacters[PirateIndex]);
	}
}
