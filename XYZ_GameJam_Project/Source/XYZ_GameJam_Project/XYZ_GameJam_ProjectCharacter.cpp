// Copyright Epic Games, Inc. All Rights Reserved.

#include "XYZ_GameJam_ProjectCharacter.h"

#include "XYZ_GameJam_ProjectPlayerController.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"

AXYZ_GameJam_ProjectCharacter::AXYZ_GameJam_ProjectCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AXYZ_GameJam_ProjectCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

void AXYZ_GameJam_ProjectCharacter::MoveUp()
{
	
	AddMovementInput(FVector::XAxisVector);
}

void AXYZ_GameJam_ProjectCharacter::MoveDown()
{
	AddMovementInput(-FVector::XAxisVector);
}

void AXYZ_GameJam_ProjectCharacter::MoveRight()
{
	AddMovementInput(FVector::YAxisVector);
}

void AXYZ_GameJam_ProjectCharacter::MoveLeft()
{
	AddMovementInput(-FVector::YAxisVector);
}


void AXYZ_GameJam_ProjectCharacter::StartFire()
{
	MakeShot();
	if (FireMode == EWeaponFireMode::FullAuto)
	{
		GetWorld()->GetTimerManager().ClearTimer(ShotTimer);
		GetWorld()->GetTimerManager().SetTimer(ShotTimer, this, &AXYZ_GameJam_ProjectCharacter::MakeShot, GetShotTimerInterval(), true);
	}
}

void AXYZ_GameJam_ProjectCharacter::StopFire()
{
	GetWorld()->GetTimerManager().ClearTimer(ShotTimer);
}

void AXYZ_GameJam_ProjectCharacter::MakeShot()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Shot."));

	OnShotEvent();
	
	if (!bIsCanShoot)
	{
		StopFire();
	}

	

	
	// CharacterOwner->PlayAnimMontage(CharacterFireMontage);
	// PlayAnimMontage(WeaponFireMontage);
	
	// AXYZ_GameJam_ProjectPlayerController* CurrentController = GetController<AXYZ_GameJam_ProjectPlayerController>();
	// if (!IsValid(CurrentController))
	// {
	// 	return;
	// }

	

	// FVector PlayerViewPoint;
	// FRotator PlayerViewRotation;
	// Controller->GetPlayerViewPoint(PlayerViewPoint, PlayerViewRotation);

	// FVector ViewDirection = PlayerViewRotation.RotateVector(FVector::ForwardVector);
	// ViewDirection += GetBulletSpreadOffset(FMath::RandRange(0.0f, GetCurrentBulletSpreadAngle()), PlayerViewRotation);
	// WeaponBarrelComponent->Shot(PlayerViewPoint, ViewDirection, Controller);
}

void AXYZ_GameJam_ProjectCharacter::OnShotEvent_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("BOOM"));

}

float AXYZ_GameJam_ProjectCharacter::GetShotTimerInterval()
{
	return 60.0f / RateOfFire;
}
