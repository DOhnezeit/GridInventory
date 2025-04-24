// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"

#include "ItemBaseDataAsset.h"
#include "Components/SphereComponent.h"

AItemBase::AItemBase()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));

	StaticMesh->SetupAttachment(RootComponent);
	SphereComponent->SetupAttachment(StaticMesh);

	StaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	ItemDataAsset = nullptr;
}

void AItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UItemBaseDataAsset* AItemBase::GetItemDataAsset() const
{
	if (ItemDataAsset != nullptr)
	{
		return ItemDataAsset;
	}
	UE_LOG(LogTemp, Error, TEXT("ItemDataAsset is nullptr"));
	return nullptr;
}

void AItemBase::InitializeItem(UItemBaseDataAsset* NewItemDataAsset)
{
	if (NewItemDataAsset != nullptr)
	{
		ItemDataAsset = NewItemDataAsset;
		if (ItemDataAsset->ItemMesh != nullptr)
		{
			StaticMesh->SetStaticMesh(ItemDataAsset->ItemMesh);
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ItemDataAsset is nullptr"));
	}
}
