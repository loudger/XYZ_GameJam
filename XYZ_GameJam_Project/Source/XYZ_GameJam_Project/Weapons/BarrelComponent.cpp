// Fill out your copyright notice in the Description page of Project Settings.


#include "BarrelComponent.h"

// Sets default values for this component's properties
UBarrelComponent::UBarrelComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UBarrelComponent::Shot(FVector ShotStart, FVector ShotDirection, AController* Controller)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Shot."));
}


// Called when the game starts
void UBarrelComponent::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void UBarrelComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

