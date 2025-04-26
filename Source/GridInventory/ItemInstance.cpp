// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemInstance.h"

#include "ItemBaseDataAsset.h"

UItemBaseDataAsset* UItemInstance::GetDataAsset() const
{
	if (ItemDataAsset)
	{
		return ItemDataAsset;
	}

	UE_LOG(LogTemp, Warning, TEXT("ItemDataAsset is nullptr"));
	return nullptr;
}
