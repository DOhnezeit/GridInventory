// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBaseDataAsset.h"

UItemBaseDataAsset::UItemBaseDataAsset(): ItemIcon(nullptr), ItemWeight(0), ItemValue(0), ItemGridSize(1,1), CanRotate(false)
{
}

void UItemBaseDataAsset::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	// Enforce minimum grid size
	if (ItemGridSize.X < 1)
	{
		ItemGridSize.X = 1;
	}
	if (ItemGridSize.Y < 1)
	{
		ItemGridSize.Y = 1;
	}
}
