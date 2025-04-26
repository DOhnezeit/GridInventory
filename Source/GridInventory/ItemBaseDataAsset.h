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
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item | Inventory Info")
	FName ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item | Inventory Info")
	FName ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item | Inventory Info")
	FName ItemDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item | Inventory Info")
	UTexture2D* ItemIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item | Inventory Info")
	float ItemWeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item | Inventory Info")
	float ItemValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item | Inventory Info")
	FIntPoint ItemGridSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item | Inventory Info")
	bool CanRotate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item | Mesh")
	UStaticMesh* ItemMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item | Mesh")
	USkeletalMesh* ItemSkeletalMesh;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
};
