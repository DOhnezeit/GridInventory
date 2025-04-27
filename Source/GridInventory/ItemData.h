// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ItemData.generated.h"

class UItemModifierContainer;
class UItemBaseDataAsset;

USTRUCT(BlueprintType)
struct GRIDINVENTORY_API FItemData
{
	GENERATED_BODY()

	public:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "0 - Item Data")
	TObjectPtr<UItemModifierContainer> ModifierContainer;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "0 - Item Data")
	TObjectPtr<UItemBaseDataAsset> ItemDataAsset;
	
};
