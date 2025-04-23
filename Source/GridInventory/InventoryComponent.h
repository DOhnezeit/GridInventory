// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GRIDINVENTORY_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, Category="IC Info | Inventory Columns")
	int32 Columns;

	UPROPERTY(EditAnywhere, Category="IC Info | Inventory Rows")
	int32 Rows;

	UPROPERTY(EditAnywhere, Category="IC Info | Inventory Tile Size")
	float TileSize;

protected:
	virtual void BeginPlay() override;

	
};
