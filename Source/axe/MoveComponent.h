// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MoveComponent.generated.h"


UCLASS( ClassGroup=(AxeCpp), meta=(BlueprintSpawnableComponent) )
class AXE_API UMoveComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoveComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	friend class FMoveComponentVisualizer;

	// Parameters
	UPROPERTY(EditAnywhere)
	FVector MoveOffSet;

	FVector MoveOffSetNormZ;
	FVector MoveOffSetNormY;
	FVector MoveOffSetNormX;

	// Speed
	UPROPERTY(EditAnywhere)
	float Speed = 1.0f;
	
	// Computed movements
	FVector StartRelativeLocation;
	FVector EndRelativeLocation;
	float MaxDist = 0.0f;
	float CurDistZ = 0.0f;
	float CurDistY = 0.0f;
	float CurDistX = 0.0f;
	float moveDirectionZ = 1.0f;
	float moveDirectionY = 1.0f;
	float moveDirectionX = 1.0f;

};
