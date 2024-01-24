// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PirateCharacter.h"

#include "Camera/CameraComponent.h"
#include "Anim/PirateAnim.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APirateCharacter::APirateCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Movement Settings
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->MaxWalkSpeed = 250.f;

	//Camera Settings
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bUsePawnControlRotation = true;

	ThirdPersonCamera = CreateDefaultSubobject<UCameraComponent>("ThirdPersonCamera");
	ThirdPersonCamera->SetupAttachment(CameraBoom);
	ThirdPersonCamera->SetActive(true);
	ThirdPersonCamera->bUsePawnControlRotation = false;

	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>("FirstPersonCamera");
	FirstPersonCamera->SetupAttachment(GetMesh());
	FirstPersonCamera->bUsePawnControlRotation = true;

	//Components Settings
	InteractorComponent = CreateDefaultSubobject<UInteractorComponent>("InteractorComponent");
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>("InventoryComponent");
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
	
	if(Animations)
	{
		Animations->Animate(this);
	}
}

void APirateCharacter::Move(const FInputActionValue& Value)
{
	// Obtains the controller's rotation and create a rotation on the yaw axis
	FVector2d MovementValue = Value.Get<FVector2d>();
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// Gets the forward and right directions based on the Yaw rotation
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// Adds movement input along the forward axis (ForwardDirection) and the right axis (RightDirection)
	AddMovementInput(ForwardDirection, MovementValue.Y);
	AddMovementInput(RightDirection, MovementValue.X);

}

void APirateCharacter::Look(const FInputActionValue& Value)
{
	FVector2d LookValue = Value.Get<FVector2d>();
	
	// Adds input to control the rotation
	AddControllerYawInput(LookValue.X);
	AddControllerPitchInput(LookValue.Y);
	
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
	//The interaction system contains Item management too
	InteractorComponent->Interact();
}

void APirateCharacter::Drop(const FInputActionValue& Value)
{
	InventoryComponent->DropItem(false);
}

void APirateCharacter::DropHalf(const FInputActionValue& Value)
{
	InventoryComponent->DropItem(true);
}

void APirateCharacter::ChangeVisual(const FInputActionValue& Value)
{
	if(FirstPersonActive) //Switch to third person camera
	{
		ThirdPersonCamera->SetActive(true);
		FirstPersonCamera->SetActive(false);
		bUseControllerRotationYaw = false;
		FirstPersonActive = false;
	}
	else //Switch to first person camera
	{
		FirstPersonCamera->SetActive(true);
		ThirdPersonCamera->SetActive(false);
		bUseControllerRotationYaw = true;
		FirstPersonActive = true;
	}
}


