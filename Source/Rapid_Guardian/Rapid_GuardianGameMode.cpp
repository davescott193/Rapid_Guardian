// Copyright Epic Games, Inc. All Rights Reserved.

#include "Rapid_GuardianGameMode.h"
#include "Rapid_GuardianPlayerController.h"
#include "Rapid_GuardianCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARapid_GuardianGameMode::ARapid_GuardianGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ARapid_GuardianPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}