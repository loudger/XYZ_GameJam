// Copyright Epic Games, Inc. All Rights Reserved.

#include "XYZ_GameJam_ProjectGameMode.h"
#include "XYZ_GameJam_ProjectPlayerController.h"
#include "XYZ_GameJam_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AXYZ_GameJam_ProjectGameMode::AXYZ_GameJam_ProjectGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AXYZ_GameJam_ProjectPlayerController::StaticClass();

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