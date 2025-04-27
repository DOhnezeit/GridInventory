// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Modifier.h"
#include "ItemModifierContainer.generated.h"

UCLASS()
class GRIDINVENTORY_API UItemModifierContainer : public UObject
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FModifier> ItemModifiers;
};
