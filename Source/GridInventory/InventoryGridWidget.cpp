// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryGridWidget.h"
#include "GridInventoryCharacter.h"
#include "InventoryComponent.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/CanvasPanelSlot.h"

void UInventoryGridWidget::NativeConstruct()
{
	Super::NativeConstruct();

	const AGridInventoryCharacter* CharacterReference = Cast<AGridInventoryCharacter>(GetOwningPlayerPawn());
	if (!CharacterReference) return;

	const UInventoryComponent* InventoryComponent = CharacterReference->InventoryComponent;
	if (!InventoryComponent) return;

	Columns = InventoryComponent->Columns; 
	Rows = InventoryComponent->Rows;
	TileSize = InventoryComponent->TileSize;

	float NewWidth = Columns * TileSize;
	float NewHeight = Rows * TileSize;

	// Store grid lines directly in optimized arrays
	GridLinesX.Empty(Columns + 1);
	GridLinesY.Empty(Rows + 1);

	UCanvasPanelSlot* BorderAsCanvasSlot = UWidgetLayoutLibrary::SlotAsCanvasSlot(GridBorder);
	if (BorderAsCanvasSlot)
	{
		BorderAsCanvasSlot->SetSize(FVector2D(NewWidth, NewHeight));
	}

	// Initialize grid line data
	CreateLineSegments();
}

void UInventoryGridWidget::CreateLineSegments()
{
	// Create horizontal grid lines
	for (int32 i = 0; i <= Rows; i++)
	{
		float Y = i * TileSize;
		GridLinesY.Add(FVector4(0.0f, Y, Columns * TileSize, Y));
	}
    
	// Create vertical grid lines
	for (int32 i = 0; i <= Columns; i++)
	{
		float X = i * TileSize;
		GridLinesX.Add(FVector4(X, 0.0f, X, Rows * TileSize));
	}
}

int32 UInventoryGridWidget::NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements,
	int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	Super::NativePaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);

	FPaintContext PaintContext(AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);
	FLinearColor GridColor(0.5f, 0.5f, 0.5f, 0.5f);
    
	if (!GridBorder) return LayerId;
    
	FVector2D TopLeftCorner = GridBorder->GetCachedGeometry().GetLocalPositionAtCoordinates(FVector2D(0.0f, 0.0f));
    
	// Draw vertical lines
	for (const FVector4& Line : GridLinesX)
	{
		UWidgetBlueprintLibrary::DrawLine(
			PaintContext,
			FVector2D(Line.X, Line.Y) + TopLeftCorner,
			FVector2D(Line.Z, Line.W) + TopLeftCorner,
			GridColor, 
			false, 
			1.0f
		);
	}
    
	// Draw horizontal lines
	for (const FVector4& Line : GridLinesY)
	{
		UWidgetBlueprintLibrary::DrawLine(
			PaintContext,
			FVector2D(Line.X, Line.Y) + TopLeftCorner,
			FVector2D(Line.Z, Line.W) + TopLeftCorner,
			GridColor, 
			false, 
			1.0f
		);
	}
    
	return LayerId;
}
