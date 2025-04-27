// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemData.h"
#include "GameFramework/Actor.h"
#include "WorldItem.generated.h"


class USphereComponent;





UCLASS()
class GRIDINVENTORY_API AWorldItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AWorldItem();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY(EditAnywhere)
	USphereComponent* SphereComponent;

	UFUNCTION(BlueprintCallable, Category = "0 | Item Data")
	const FItemData& GetItemData() const;
	
	void InitializeItem(const FItemData* InItemData);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "0 | Item Data")
	FItemData ItemData;
	
protected:
	virtual void BeginPlay() override;

	void ResetItem();
	
	virtual void OnConstruction(const FTransform& Transform) override;
};
