// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction\InteractableJumper.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

AInteractableJumper::AInteractableJumper()
{
	PrimaryActorTick.bCanEverTick = true;
	
	NeedInput = false;
	
	Collider = CreateDefaultSubobject<USphereComponent>("Collider");
	Collider->SetupAttachment(RootComponent);
	Collider->OnComponentBeginOverlap.AddDynamic(this, &AInteractableJumper::OnOverlapBegin);
	Collider->OnComponentEndOverlap.AddDynamic(this, &AInteractableJumper::OnEndOverlap);
}

void AInteractableJumper::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                            UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Interactor = Cast<ACharacter>(OtherActor);
	if(Interactor)
	{
		Activate();
	}
	
}

void AInteractableJumper::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Deactivate();
}

void AInteractableJumper::Activate()
{
	Super::Activate();
		//Save the JumpZVelocity to reset on Deactivate
		InitialJumpSpeed = Interactor->GetCharacterMovement()->JumpZVelocity;
		//Change the JumpZVelocity
		Interactor->GetCharacterMovement()->JumpZVelocity = JumpSpeed;

	
}

void AInteractableJumper::Deactivate()
{
	Super::Deactivate();
	//Reset the JumpZVelocity
	Interactor->GetCharacterMovement()->JumpZVelocity = InitialJumpSpeed;
}