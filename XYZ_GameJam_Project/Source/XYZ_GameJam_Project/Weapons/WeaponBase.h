// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BarrelComponent.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"


UENUM(BlueprintType)
enum class EWeaponFireMode : uint8
{
	Single,
	FullAuto
};

UCLASS()
class XYZ_GAMEJAM_PROJECT_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();

	
	void StartFire();
	void StopFire();
	
	void MakeShot();

	bool bIsCanShoot;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Скорострельность в минуту
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon | Parameters", meta = (ClampMin = 1.0f, UIMin = 1.0f))
	float RateOfFire = 300;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon | FireMode")
	EWeaponFireMode FireMode = EWeaponFireMode::Single;

public:	
	FTimerHandle ShotTimer;

	float GetShotTimerInterval();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBarrelComponent* WeaponBarrelComponent;
};



