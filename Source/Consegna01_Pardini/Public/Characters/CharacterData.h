#pragma once

#include "CoreMinimal.h"
#include "PirateCharacter.h"
#include "GameFramework/PlayerStart.h"
#include "CharacterData.generated.h"

USTRUCT(BlueprintType)
struct FCharacterData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category="Setup")
	FString PirateName;
	UPROPERTY(EditAnywhere, Category="Setup")
	FName PlayerStartTag;
	UPROPERTY(EditAnywhere, Category="Setup")
	TSubclassOf<APirateCharacter> Pirate;
};
