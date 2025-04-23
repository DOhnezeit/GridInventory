// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryDataStructs.generated.h"

USTRUCT()
struct FLines
{
	GENERATED_BODY()
	
	FLines() {};
	
	TArray<FVector2D> XLines;
	TArray<FVector2D> YLines;
	
};

class GRIDINVENTORY_API InventoryDataStructs
{
public:
	
};
