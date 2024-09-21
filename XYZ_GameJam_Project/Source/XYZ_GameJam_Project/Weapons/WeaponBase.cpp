// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"

#include "XYZ_GameJam_Project/XYZ_GameJam_ProjectCharacter.h"
#include "XYZ_GameJam_Project/XYZ_GameJam_ProjectPlayerController.h"

// Sets default values
AWeaponBase::AWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	WeaponMesh->SetupAttachment(RootComponent);

	WeaponBarrelComponent = CreateDefaultSubobject<UBarrelComponent>("WeaponBarrelComponent");
	// WeaponBarrelComponent->SetupAttachment(WeaponMesh, SocketWeaponMuzzle);
}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

float AWeaponBase::GetShotTimerInterval()
{
	return 60.0f / RateOfFire;
}

void AWeaponBase::StartFire()
{
	MakeShot();
	if (FireMode == EWeaponFireMode::FullAuto)
	{
		GetWorld()->GetTimerManager().ClearTimer(ShotTimer);
		GetWorld()->GetTimerManager().SetTimer(ShotTimer, this, &AWeaponBase::MakeShot, GetShotTimerInterval(), true);
	}
}

void AWeaponBase::StopFire()
{
	GetWorld()->GetTimerManager().ClearTimer(ShotTimer);
}

void AWeaponBase::MakeShot()
{
	checkf(GetOwner()->IsA<AXYZ_GameJam_ProjectCharacter>(), TEXT("AWeaponBase::Fire. Only AXYZ_GameJam_ProjectCharacter can be an owner of RangeWeapon"))
	AXYZ_GameJam_ProjectCharacter* CharacterOwner = StaticCast<AXYZ_GameJam_ProjectCharacter*>(GetOwner());

	if (!bIsCanShoot)
	{
		StopFire();
	}

	// CharacterOwner->PlayAnimMontage(CharacterFireMontage);
	// PlayAnimMontage(WeaponFireMontage);
	
	AXYZ_GameJam_ProjectPlayerController* Controller = CharacterOwner->GetController<AXYZ_GameJam_ProjectPlayerController>();
	if (!IsValid(Controller))
		return;

	// FVector PlayerViewPoint;
	// FRotator PlayerViewRotation;
	// Controller->GetPlayerViewPoint(PlayerViewPoint, PlayerViewRotation);

	// FVector ViewDirection = PlayerViewRotation.RotateVector(FVector::ForwardVector);
	// ViewDirection += GetBulletSpreadOffset(FMath::RandRange(0.0f, GetCurrentBulletSpreadAngle()), PlayerViewRotation);
	// WeaponBarrelComponent->Shot(PlayerViewPoint, ViewDirection, Controller);
}

