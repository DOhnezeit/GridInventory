// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

class USphereComponent;
class UItemBaseDataAsset;

UCLASS()
class GRIDINVENTORY_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AItemBase();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* SphereComponent;

	UFUNCTION(BlueprintCallable, Category = "Item")
	UItemBaseDataAsset* GetItemDataAsset() const;

	void InitializeItem(UItemBaseDataAsset* NewItemDataAsset);
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	UItemBaseDataAsset* ItemDataAsset;
};
