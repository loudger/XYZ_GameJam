// Copyright Epic Games, Inc. All Rights Reserved.

#include "XYZ_GameJam_ProjectPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "XYZ_GameJam_ProjectCharacter.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

AXYZ_GameJam_ProjectPlayerController::AXYZ_GameJam_ProjectPlayerController()
{
}

void AXYZ_GameJam_ProjectPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	CachedBaseCharacter = Cast<AXYZ_GameJam_ProjectCharacter>(InPawn);
}


void AXYZ_GameJam_ProjectPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveUp", this, &AXYZ_GameJam_ProjectPlayerController::MoveUp);
	InputComponent->BindAxis("MoveRight", this, &AXYZ_GameJam_ProjectPlayerController::MoveRight);
}

void AXYZ_GameJam_ProjectPlayerController::MoveUp(float X)
{
	if (!FMath::IsNearlyZero(X))
	{
		if (X > 0.0f)
		{
			CachedBaseCharacter->MoveUp();
		} else
		{
			CachedBaseCharacter->MoveDown();
		}
	}
}

void AXYZ_GameJam_ProjectPlayerController::MoveRight(float X)
{
	if (!FMath::IsNearlyZero(X))
	{
		if (X > 0.0f)
		{
			CachedBaseCharacter->MoveRight();
		} else
		{
			CachedBaseCharacter->MoveLeft();
		}
	}
}


