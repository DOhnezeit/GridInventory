// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldItem.h"

#include "ItemBaseDataAsset.h"
#include "ItemData.h"
#include "Components/SphereComponent.h"

AWorldItem::AWorldItem()
{
	PrimaryActorTick.bCanEverTick = false;
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetupAttachment(RootComponent);
	
}

void AWorldItem::BeginPlay()
{
	Super::BeginPlay();

	InitializeItem(&ItemData);
}

void AWorldItem::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	ResetItem();
	
	if (ItemData.ItemDataAsset)
	{
		if (ItemData.ItemDataAsset->ItemMesh)
		{
			StaticMesh = NewObject<UStaticMeshComponent>(this, TEXT("StaticMeshComponent"));
			StaticMesh->SetupAttachment(RootComponent);
			StaticMesh->RegisterComponent();
			StaticMesh->SetStaticMesh(ItemData.ItemDataAsset->ItemMesh);
			StaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
		else if (ItemData.ItemDataAsset->ItemSkeletalMesh)
		{
			SkeletalMesh = NewObject<USkeletalMeshComponent>(this, TEXT("SkeletalMeshComponent"));
			SkeletalMesh->SetupAttachment(RootComponent);
			SkeletalMesh->RegisterComponent();
			SkeletalMesh->SetSkeletalMesh(ItemData.ItemDataAsset->ItemSkeletalMesh);
			SkeletalMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("ItemDataAsset does not have an ItemMesh or ItemSkeletalMesh"));
		}
	}
}

void AWorldItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

const FItemData& AWorldItem::GetItemData() const
{
	return ItemData;
}

void AWorldItem::InitializeItem(const FItemData* InItemData)
{
	if (InItemData)
	{
		ItemData = *InItemData;
		ResetItem();

		// Check if ItemDataAsset is valid
		if (!ItemData.ItemDataAsset)
		{
			UE_LOG(LogTemp, Error, TEXT("ItemDataAsset is nullptr in InitializeItem"));
			return;
		}

		// Check for ItemMesh or ItemSkeletalMesh
		if (ItemData.ItemDataAsset->ItemMesh)
		{
			StaticMesh = NewObject<UStaticMeshComponent>(this, TEXT("StaticMeshComponent"));
			StaticMesh->SetupAttachment(RootComponent);
			StaticMesh->RegisterComponent();
			StaticMesh->SetStaticMesh(ItemData.ItemDataAsset->ItemMesh);
			StaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
		else if (ItemData.ItemDataAsset->ItemSkeletalMesh)
		{
			SkeletalMesh = NewObject<USkeletalMeshComponent>(this, TEXT("SkeletalMeshComponent"));
			SkeletalMesh->SetupAttachment(RootComponent);
			SkeletalMesh->RegisterComponent();
			SkeletalMesh->SetSkeletalMesh(ItemData.ItemDataAsset->ItemSkeletalMesh);
			SkeletalMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("ItemDataAsset does not have an ItemMesh or ItemSkeletalMesh"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ItemData is nullptr in InitializeItem"));
	}
}

void AWorldItem::ResetItem()
{
	if (StaticMesh)
	{
		StaticMesh->DestroyComponent();
		StaticMesh = nullptr;
	}

	if (SkeletalMesh)
	{
		SkeletalMesh->DestroyComponent();
		SkeletalMesh = nullptr;
	}
}
