// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "CPPLesson02GameMode.h"
#include "CPPLesson02HUD.h"
#include "CPPLesson02Character.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

ACPPLesson02GameMode::ACPPLesson02GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ACPPLesson02HUD::StaticClass();
}

void ACPPLesson02GameMode::CompleteMission(APawn* InstigatorPawn)
{
	if (InstigatorPawn)
	{
		InstigatorPawn->DisableInput(nullptr);
		AActor* NewViewTarget;
		TArray<AActor*> ReturnedActors;
		UGameplayStatics::GetAllActorsOfClass(this, SpectatingCameraClass, ReturnedActors);

		NewViewTarget = ReturnedActors[0];
		APlayerController* PC = Cast<APlayerController>(InstigatorPawn->GetController());

		PC->SetViewTargetWithBlend(NewViewTarget, 5.0f, EViewTargetBlendFunction::VTBlend_Cubic);
	}

	OnMissionCompleted(InstigatorPawn);
}

	// Following is the best practice of checking each pointers 
	//------------------------------------------------------------
	//	if (SpectatingCameraClass)
	//	{
	//		TArray<AActor*> ReturnedActors;
	//		UGameplayStatics::GetAllActorsOfClass(this, SpectatingCameraClass, ReturnedActors);
	//		if (ReturnedActors.Num() > 0)
	//		{
	//			AActor* NewViewTarget = ReturnedActors[0];
	//			APlayerController* PC = Cast<APlayerController>(InstigatorPawn->GetController());
	//			if (PC)
	//			{
	//				PC->SetViewTargetWithBlend(NewViewTarget, 5.0f, EViewTargetBlendFunction::VTBlend_Cubic);
	//			}
	//		}
	//	}
	//	else
	//	{
	//		UE_LOG(LogTemp, Warning, TEXT("Not found?"))
	//	}
	//}
