// Fill out your copyright notice in the Description page of Project Settings.

#include "Titanium.h"
#include "TitaniumGameMode.h"
#include "GameHUD.h"


ATitaniumGameMode::ATitaniumGameMode()
{
	HUDClass = AGameHUD::StaticClass();
}
