// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"

#include "ItemBaseDataAsset.h"
#include "ItemInstance.h"
#include "Components/SphereComponent.h"

AItemBase::AItemBase()
{
	PrimaryActorTick.bCanEverTick = false;

	IsInitialized = false;
	
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetupAttachment(RootComponent);

	ItemInstance = nullptr;
}

void AItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UItemInstance* AItemBase::GetItemInstance() const
{
	if (ItemInstance != nullptr)
	{
		return ItemInstance;
	}
	UE_LOG(LogTemp, Error, TEXT("ItemDataAsset is nullptr"));
	return nullptr;
}

UItemBaseDataAsset* AItemBase::GetBaseDataAsset() const
{
	if (ItemDataAsset)
	{
		return ItemDataAsset;
	}
	
	if (!ItemInstance)
	{
		UE_LOG(LogTemp, Error, TEXT("ItemInstance is nullptr"));
		return nullptr;
	}

	UItemBaseDataAsset* DataAsset = ItemInstance->GetDataAsset();

	
	if (!DataAsset)
	{
		UE_LOG(LogTemp, Error, TEXT("ItemDataAsset is nullptr"));
		return nullptr;
	}
	return DataAsset;
}

void AItemBase::InitializeItem(UItemInstance* NewItemInstance)
{
	if (NewItemInstance != nullptr)
	{
		ItemInstance = NewItemInstance;
		if (ItemInstance->GetDataAsset())
		{
			ItemDataAsset = ItemInstance->GetDataAsset();
		}
		
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed Item initialization: ItemDataAsset is nullptr"));
		}
		
		if (ItemDataAsset->ItemMesh)
		{
			StaticMesh = NewObject<UStaticMeshComponent>(this);
			StaticMesh->SetupAttachment(RootComponent);
			StaticMesh->RegisterComponent();
			StaticMesh->SetStaticMesh(ItemDataAsset->ItemMesh);
			StaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			
			IsInitialized = true;
		}

		else if (ItemDataAsset->ItemSkeletalMesh)
		{
			SkeletalMesh = NewObject<USkeletalMeshComponent>(this);
			SkeletalMesh->SetupAttachment(RootComponent);
			SkeletalMesh->RegisterComponent();
			SkeletalMesh->SetSkeletalMesh(ItemDataAsset->ItemSkeletalMesh);
			SkeletalMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

			IsInitialized = true;
		}
		
		else
		{
			UE_LOG(LogTemp, Error, TEXT("ItemDataAsset does not have an ItemMesh"));
		}
	}
	
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ItemDataAsset is nullptr"));
	}
}
