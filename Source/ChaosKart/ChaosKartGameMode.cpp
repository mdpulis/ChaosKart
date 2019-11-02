// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ChaosKartGameMode.h"
#include "ChaosKartPawn.h"
#include "ChaosKartHud.h"

AChaosKartGameMode::AChaosKartGameMode()
{
	DefaultPawnClass = AChaosKartPawn::StaticClass();
	HUDClass = AChaosKartHud::StaticClass();
}
