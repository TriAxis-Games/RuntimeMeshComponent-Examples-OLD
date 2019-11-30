// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "RuntimeMeshExamplesGameMode.h"
#include "RuntimeMeshExamplesHUD.h"
#include "RuntimeMeshExamplesCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARuntimeMeshExamplesGameMode::ARuntimeMeshExamplesGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ARuntimeMeshExamplesHUD::StaticClass();
}
