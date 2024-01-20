// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/InteractableLaunchPad.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

AInteractableLaunchPad::AInteractableLaunchPad()
{
	PrimaryActorTick.bCanEverTick = true;
	
	NeedInput = false;
	
	Collider = CreateDefaultSubobject<USphereComponent>("Collider");
	Collider->SetupAttachment(RootComponent);
	Collider->OnComponentBeginOverlap.AddDynamic(this, &AInteractableLaunchPad::OnOverlapBegin);
	Collider->OnComponentEndOverlap.AddDynamic(this, &AInteractableLaunchPad::OnEndOverlap);
}

void AInteractableLaunchPad::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                            UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Interactor = Cast<ACharacter>(OtherActor);
	if(Interactor)
	{
		Activate();
	}
	
}

void AInteractableLaunchPad::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Deactivate();
}

void AInteractableLaunchPad::Activate()
{
	Super::Activate();
		//Save the JumpZVelocity to reset on Deactivate
		InitialJumpSpeed = Interactor->GetCharacterMovement()->JumpZVelocity;
		//Change the JumpZVelocity
		Interactor->GetCharacterMovement()->JumpZVelocity = JumpSpeed;

	
}

void AInteractableLaunchPad::Deactivate()
{
	Super::Deactivate();
	//Reset the JumpZVelocity
	Interactor->GetCharacterMovement()->JumpZVelocity = InitialJumpSpeed;
}
