// Copyright Epic Games, Inc. All Rights Reserved.

#include "HoloBoomPickUpComponent.h"

UHoloBoomPickUpComponent::UHoloBoomPickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UHoloBoomPickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UHoloBoomPickUpComponent::OnSphereBeginOverlap);
}

void UHoloBoomPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AHLB_Player* Character = Cast<AHLB_Player>(OtherActor);
	if (Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}