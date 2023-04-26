// Fill out your copyright notice in the Description page of Project Settings.


#include "MovableComponent.h"

// Sets default values for this component's properties
UMovableComponent::UMovableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMovableComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	actor = GetOwner();
	startLocation = actor->GetActorLocation();
}


// Called every frame
void UMovableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	Move(DeltaTime);
}

void UMovableComponent::Move(float deltaTime) {
	FVector currentLocation = actor->GetActorLocation();
	FVector newLocation = currentLocation + (axis * speed * deltaTime);
	if (FVector::Dist(startLocation, newLocation) <= maxDistance)
		actor->SetActorLocation(newLocation);
}