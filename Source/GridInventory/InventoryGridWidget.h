// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Included
#include "Components/Border.h"
#include "Components/CanvasPanel.h"

// Engine
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryGridWidget.generated.h"

class UCanvasPanel;
class UBorder;

UCLASS()
class GRIDINVENTORY_API UInventoryGridWidget : public UUserWidget
{
	GENERATED_BODY()


protected:

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "UI")
	UCanvasPanel* Canvas;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "UI")
	UBorder* GridBorder;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "UI")
	UCanvasPanel* GridCanvasPanel;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "UI")
	int32 Columns;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "UI")
	int32 Rows;

	float TileSize;

	TArray<FVector4> GridLinesX;
	TArray<FVector4> GridLinesY;
	
	// Functions

	virtual void NativeConstruct() override;
	void CreateLineSegments();

	virtual int32 NativePaint(const FPaintArgs& Args,
		const FGeometry& AllottedGeometry,
		const FSlateRect& MyCullingRect,
		FSlateWindowElementList& OutDrawElements,
		int32 LayerId,
		const FWidgetStyle& InWidgetStyle,
		bool bParentEnabled) const override;
};
