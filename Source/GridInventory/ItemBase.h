// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

class USphereComponent;
class UItemInstance;
class UItemBaseDataAsset;



UCLASS()
class GRIDINVENTORY_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AItemBase();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY(EditAnywhere)
	USphereComponent* SphereComponent;

	UPROPERTY(VisibleAnywhere)
	bool IsInitialized;

	UFUNCTION(BlueprintCallable, Category = "Item Data")
	UItemInstance* GetItemInstance() const;

	UFUNCTION(BlueprintCallable, Category = "Item Data")
	UItemBaseDataAsset* GetBaseDataAsset() const;
	
	void InitializeItem(UItemInstance* NewItemInstance);

	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Data")
	UItemInstance* ItemInstance;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Data")
	UItemBaseDataAsset* ItemDataAsset;
};
