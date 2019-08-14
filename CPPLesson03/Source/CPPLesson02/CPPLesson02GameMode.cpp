// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "CPPLesson02GameMode.h"
#include "CPPLesson02HUD.h"
#include "CPPLesson02Character.h"
#include "UObject/ConstructorHelpers.h"

ACPPLesson02GameMode::ACPPLesson02GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ACPPLesson02HUD::StaticClass();
}
