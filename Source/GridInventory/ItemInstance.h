// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemData.h"

#include "ItemInstance.generated.h"

class UItemBaseDataAsset;

UCLASS()
class GRIDINVENTORY_API UItemInstance : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	const FItemData& GetItemData() const;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Data")
	FItemData ItemData;
};
