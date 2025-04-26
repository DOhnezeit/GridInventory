

// THIS CLASS IS A PLACEHOLDER FOR A FUTURE MODIFIER IMPLEMENTATION

#pragma once

#include "CoreMinimal.h"
#include "Modifier.generated.h"

UENUM(BlueprintType)
enum class EModifierType : uint8
{
	Damage UMETA(DisplayName = "Damage"),
	AttackSpeed UMETA(DisplayName = "Attack Speed"),
	Ammo UMETA(DisplayName = "Ammo"),
};

USTRUCT(BlueprintType)
struct FModifier
{
	GENERATED_BODY()

	EModifierType Type;
	float Value;
	bool IsPercentageModifier;
};