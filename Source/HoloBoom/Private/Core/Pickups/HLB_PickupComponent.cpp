// Xarblanca Studios 2025. All rights reserved.

#include "Core/Pickups/HLB_PickupComponent.h"

#include "Characters/Player/HLB_Player.h"
#include "Core/Pickups/HLB_Pickup.h"

void UHLB_PickupComponent::BeginPlay()
{
	Super::BeginPlay();

	if (!OnComponentBeginOverlap.Contains(this, TEXT("OnSphereBeginOverlap")))
		OnComponentBeginOverlap.AddDynamic(this, &UHLB_PickupComponent::OnSphereBeginOverlap);
}

void UHLB_PickupComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (OnComponentBeginOverlap.Contains(this, TEXT("OnSphereBeginOverlap")))
		OnComponentBeginOverlap.RemoveDynamic(this, &UHLB_PickupComponent::OnSphereBeginOverlap);
}

void UHLB_PickupComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AHLB_Player* Player = Cast<AHLB_Player>(OtherActor);

	if (Player)
	{
		AHLB_Pickup* Pickup = Cast<AHLB_Pickup>(GetOwner());

		if (Pickup)
			Pickup->Pick(Player);
	}
}