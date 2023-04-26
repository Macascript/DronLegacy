// Fill out your copyright notice in the Description page of Project Settings.


#include "RotableComponent.h"

// Sets default values for this component's properties
URotableComponent::URotableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URotableComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	actor = GetOwner();
	startRotation = actor->GetActorRotation();
}


// Called every frame
void URotableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	Rotate(DeltaTime);
}

void URotableComponent::Rotate(float deltaTime) {
	FRotator currentRotation = actor->GetActorRotation();
	FRotator newRotation = currentRotation + (axis * speed * deltaTime);
	if (FMath::Abs(axis.Roll) > 0.0f && FMath::Abs(startRotation.Roll - newRotation.Roll) <= maxAngle)
		actor->SetActorRotation(newRotation);
	else if (FMath::Abs(axis.Pitch) > 0.0f && FMath::Abs(startRotation.Pitch - newRotation.Pitch) <= maxAngle)
		actor->SetActorRotation(newRotation);
	else if (FMath::Abs(axis.Yaw) > 0.0f && FMath::Abs(startRotation.Yaw - newRotation.Yaw) <= maxAngle)
		actor->SetActorRotation(newRotation);
}