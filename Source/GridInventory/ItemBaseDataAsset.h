// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"


#include "ItemBaseDataAsset.generated.h"

UCLASS()
class GRIDINVENTORY_API UItemBaseDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UItemBaseDataAsset();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	FName ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	FName ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	FName ItemDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	UTexture2D* ItemIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	float ItemWeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	float ItemValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	FIntPoint ItemGridSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	bool CanRotate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	UStaticMesh* ItemMesh;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
};
