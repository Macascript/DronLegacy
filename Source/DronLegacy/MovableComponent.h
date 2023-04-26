// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MovableComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DRONLEGACY_API UMovableComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	FVector startLocation;
	AActor* actor;

	void Move(float deltaTime);

public:	
	UPROPERTY(EditAnywhere) float maxDistance = 10.0f;

	// Sets default values for this component's properties
	UMovableComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere) FVector axis;
	UPROPERTY(EditAnywhere) float speed;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
