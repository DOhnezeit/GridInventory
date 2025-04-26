// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ItemInstance.generated.h"

class UItemBaseDataAsset;

UCLASS()
class GRIDINVENTORY_API UItemInstance : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	UItemBaseDataAsset* GetDataAsset() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Instance")
	UItemBaseDataAsset* ItemDataAsset;

	// Placeholder for later Modifier implementations, could loop through modifiers with a GetModifiedStat() function + enum
	// UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Instance")
	// TArray<FItemModifier> Modifiers;

	
};
