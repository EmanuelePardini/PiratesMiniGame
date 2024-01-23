// Fill out your copyright notice in the Description page of Project Settings.


#include "Anim/PirateAnim.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UPirateAnim::Animate(ACharacter* Character)
{
		//TODO: Risolvere i bug delle anim al cambiamento del personaggio
		//Get absolute values of Velocity
		FVector Velocity = Character->GetCharacterMovement()->Velocity.GetAbs();
	
		//Update the parameters based on the character movement
		Grounded = !Character->GetCharacterMovement()->IsFalling();
		SpeedX = Velocity.X;
		SpeedY = Velocity.Y;


}