#pragma once

#include "CoreMinimal.h"
#include "PirateCharacter.h"
#include "CharacterData.generated.h"

USTRUCT(BlueprintType)
struct FCharacterData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	FString PirateName;
	UPROPERTY(EditAnywhere)
	TSubclassOf<APirateCharacter> Pirate;
};
