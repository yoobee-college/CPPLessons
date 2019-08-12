// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "CPPLesson01GameMode.h"
#include "CPPLesson01HUD.h"
#include "CPPLesson01Character.h"
#include "UObject/ConstructorHelpers.h"

ACPPLesson01GameMode::ACPPLesson01GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ACPPLesson01HUD::StaticClass();
}
