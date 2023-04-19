// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class DRONLEGACY_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	FVector StartLocation;

	void MoveDoor(float DeltaTime);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere) FString DoorName = "Default name";
	UPROPERTY(EditAnywhere) FVector Axes;
	UPROPERTY(EditAnywhere) float Speed;

	
	UPROPERTY(EditAnywhere) float MaxDistanceToMove = 1000.0f;
};
