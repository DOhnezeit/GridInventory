// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryGridWidget.h"

void UInventoryGridWidget::NativeConstruct()
{
	Super::NativeConstruct();

	
}

void UInventoryGridWidget::CreateLineSegments()
{

	
}

int32 UInventoryGridWidget::NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements,
	int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	Super::NativePaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);

	return 0;
}
