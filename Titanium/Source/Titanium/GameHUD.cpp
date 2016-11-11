// Copyright 2016 Christian Holt

#include "Titanium.h"
#include "GameHUD.h"

#define OUT

AGameHUD::AGameHUD() {
	static ConstructorHelpers::FObjectFinder<UFont> HUDFontObject (TEXT("Font'/Game/WhateverItTakes.WhateverItTakes'"));
	HUDFont = HUDFontObject.Object;
	TemperatureVisible = false;
	TemperatureString = "Temperature is NONE";
}

void AGameHUD::DrawHUD()
{
	FVector2D ScreenDimensions = FVector2D(Canvas->SizeX, Canvas->SizeY);

	Super::DrawHUD();
	if (TemperatureVisible) {
		FVector2D TextSize;
		GetTextSize(TemperatureString, OUT TextSize.X, OUT TextSize.Y, HUDFont);
		DrawText(TemperatureString, FColor::White, (ScreenDimensions.X - TextSize.X) / 2, (ScreenDimensions.Y - TextSize.Y) / 2, HUDFont);
	}
}

void AGameHUD::SetTemperatureVisibility(bool isVisible)
{
	TemperatureVisible = isVisible;
}

void AGameHUD::SetTemperatureString(FString text)
{
	TemperatureString = text;
}