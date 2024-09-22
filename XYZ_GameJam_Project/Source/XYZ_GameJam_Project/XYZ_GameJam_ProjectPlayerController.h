// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "XYZ_GameJam_ProjectCharacter.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/PlayerController.h"
#include "XYZ_GameJam_ProjectPlayerController.generated.h"

/** Forward declaration to improve compiling times */
class UNiagaraSystem;
class UInputMappingContext;
class UInputAction;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS()
class AXYZ_GameJam_ProjectPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AXYZ_GameJam_ProjectPlayerController();

	virtual void SetPawn(APawn* InPawn) override;


protected:
	virtual void SetupInputComponent() override;

	void MoveUp(float X);
	void MoveRight(float X);

	UFUNCTION (BlueprintCallable)
	void FireStart();

	UFUNCTION(BlueprintCallable)
	void FireStop();

	
	TSoftObjectPtr<AXYZ_GameJam_ProjectCharacter> CachedBaseCharacter = nullptr;
};


