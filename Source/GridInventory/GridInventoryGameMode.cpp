// Copyright Epic Games, Inc. All Rights Reserved.

#include "GridInventoryGameMode.h"
#include "GridInventoryCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGridInventoryGameMode::AGridInventoryGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
