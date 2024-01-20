// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/InteractorComponent.h"

#include "Interaction/Interactable.h"

// Sets default values for this component's properties
UInteractorComponent::UInteractorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteractorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInteractorComponent::Interact()
{
	//Variables Declaration
	UWorld* Context = GetWorld();
	AActor* Owner = GetOwner();
	FVector Start = Owner->GetActorLocation();
	FVector End = Start + Owner->GetActorForwardVector() * InteractionDistance;
	TArray<FHitResult> Hits;

	//Interaction LineTrace
	//DrawDebugLine(Context, Start, End, FColor::Green, false);
	Context->LineTraceMultiByProfile(Hits, Start, End, InteractionMask);

	//For all interaction activate the interactables
	for(FHitResult Hit : Hits)
	{
		AActor* HittedActor = Hit.GetActor();
		AInteractable* Interactable = Cast<AInteractable>(HittedActor);
		
		if(Interactable && Interactable->NeedInput)
		{
			Interactable->Activate();
		}
	}
}

