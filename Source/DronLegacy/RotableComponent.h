// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RotableComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DRONLEGACY_API URotableComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	FRotator startRotation;
	AActor* actor;

	void Rotate(float deltaTime);

public:	
	UPROPERTY(EditAnywhere) float maxAngle = 90.0f;
	UPROPERTY(EditAnywhere) FRotator axis;
	UPROPERTY(EditAnywhere) float speed;

	// Sets default values for this component's properties
	URotableComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
