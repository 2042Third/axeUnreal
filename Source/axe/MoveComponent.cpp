// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveComponent.h"

// Sets default values for this component's properties
UMoveComponent::UMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	// Set start location
	StartRelativeLocation = GetRelativeLocation();

	MoveOffSetNormZ.Z = MoveOffSet.Z;
	MoveOffSetNormZ.Normalize();
	MoveOffSetNormY.Y = MoveOffSet.Y;
	MoveOffSetNormY.Normalize();
	MoveOffSetNormX.X = MoveOffSet.X;
	MoveOffSetNormX.Normalize();

	// Max setting
	MaxDist = MoveOffSet.Length();
}


// Called every frame
void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Set Current distance
	CurDistZ += DeltaTime * Speed * moveDirectionZ;
	CurDistY += DeltaTime * Speed * moveDirectionY;
	CurDistX += DeltaTime * Speed * moveDirectionX;

	if (CurDistZ >= MoveOffSet.Z || CurDistZ <= 0.0f) {
		moveDirectionZ *= -1.0f;
	}
	if (CurDistY >= MoveOffSet.Y || CurDistY <= 0.0f) {
		moveDirectionY *= -1.0f;
	}
	if (CurDistX >= MoveOffSet.X || CurDistX <= 0.0f) {
		moveDirectionX *= -1.0f;
	}

	// Compute
	this->SetRelativeLocation(StartRelativeLocation
		+ MoveOffSetNormZ * CurDistZ
		+ MoveOffSetNormY * CurDistY
		+ MoveOffSetNormX * CurDistX);
}

