// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/KillerBoxComponent.h"

#include "Characters/PiratesPlayerController.h"
#include "GameFramework/Character.h"

UKillerBoxComponent::UKillerBoxComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	OnComponentBeginOverlap.AddDynamic(this, &UKillerBoxComponent::OnOverlapBegin);
}


void UKillerBoxComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                         UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACharacter* Player = Cast<ACharacter>(OtherActor);
	
	if(Player)
	{
		Kill(Player);
	}
	
}

void UKillerBoxComponent::Kill(ACharacter* Character)
{
	APiratesPlayerController* Controller = Cast<APiratesPlayerController>(Character->GetController());
	if(Controller)
	{
		Controller->ChangeCharacter(true);
		Character->Destroy();
	}
}

