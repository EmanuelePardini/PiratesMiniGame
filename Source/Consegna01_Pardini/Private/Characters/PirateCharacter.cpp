// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PirateCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APirateCharacter::APirateCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Movement Settings
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->MaxWalkSpeed = 250.f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bUsePawnControlRotation = true;

	ThirdPersonCamera = CreateDefaultSubobject<UCameraComponent>("ThirdPersonCamera");
	ThirdPersonCamera->SetupAttachment(CameraBoom);
	ThirdPersonCamera->SetActive(true);
	ThirdPersonCamera->bUsePawnControlRotation = true;

	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>("FirstPersonCamera");
	FirstPersonCamera->SetupAttachment(GetMesh());
	FirstPersonCamera->bUsePawnControlRotation = true;
	
}

// Called when the game starts or when spawned
void APirateCharacter::BeginPlay()
{
	Super::BeginPlay();
	Animations = Cast<UPirateAnim>(GetMesh()->GetAnimInstance());
}

// Called every frame
void APirateCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Animate();
}

void APirateCharacter::Animate()
{
	//Animations->SpeedX = GetCharacterMovement()->Velocity.X;
	//Animations->SpeedY = GetCharacterMovement()->Velocity.Y;
}

void APirateCharacter::Move(const FInputActionValue& Value)
{
	FVector2d MovementValue = Value.Get<FVector2d>();

	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0,Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(ForwardDirection, MovementValue.Y);
	AddMovementInput(RightDirection, MovementValue.X);
}

void APirateCharacter::Look(const FInputActionValue& Value)
{
	FVector2d LookValue = Value.Get<FVector2d>();

	AddControllerYawInput(LookValue.X);
	AddControllerPitchInput(-LookValue.Y);
	
}

void APirateCharacter::Run(const FInputActionValue& Value)
{
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
}

void APirateCharacter::EndRun(const FInputActionValue& Value)
{
	GetCharacterMovement()->MaxWalkSpeed = 250.f;
}


void APirateCharacter::Interact(const FInputActionValue& Value)
{
	//TODO: Implement Interact
	GEngine->AddOnScreenDebugMessage(1,8,FColor::Red, TEXT("To Implement Interact"));
}

void APirateCharacter::Drop(const FInputActionValue& Value)
{
	//TODO: Implement Drop
	GEngine->AddOnScreenDebugMessage(1,8,FColor::Red, TEXT("To Implement Drop"));
}

void APirateCharacter::ChangeVisual(const FInputActionValue& Value)
{
	if(FirstPersonActive)
	{
		ThirdPersonCamera->SetActive(true);
		FirstPersonCamera->SetActive(false);
		bUseControllerRotationYaw = false;
		FirstPersonActive = false;
	}
	else
	{
		FirstPersonCamera->SetActive(true);
		ThirdPersonCamera->SetActive(false);
		bUseControllerRotationYaw = true;
		FirstPersonActive = true;
	}
}


