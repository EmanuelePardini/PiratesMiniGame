// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/InteractableMissionBox.h"

#include "CustomHUD.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

AInteractableMissionBox::AInteractableMissionBox()
{
	NeedInput = false;

	//Setup Collider
	Collider = CreateDefaultSubobject<UBoxComponent>("Collider");
	Collider->SetupAttachment(RootComponent);
	Collider->OnComponentBeginOverlap.AddDynamic(this, &AInteractableMissionBox::OnOverlapBegin);
}

void AInteractableMissionBox::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                             UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACharacter* Character = Cast<ACharacter>(OtherActor);
	if(Character)
	{
		Activate();
	}
}

void AInteractableMissionBox::Activate(ACharacter* Interactor)
{
	Super::Activate(Interactor);
	ACustomHUD* CustomHUD = Cast<ACustomHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
	if(CustomHUD)
	{
		CustomHUD->SetTopLeftText(NextMission);
		Destroy();
	}
}
