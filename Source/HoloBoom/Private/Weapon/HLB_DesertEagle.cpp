// Xarblanca Studios 2025. All rights reserved.

#include "Weapon/HLB_DesertEagle.h"

#include "Characters/HLB_Character.h"
#include "Core/ActorComponents/HLB_HealthComponent.h"
#include "InputTriggers.h"

bool UHLB_DesertEagle::ShootImpl(FVector Start, FVector Direction, AActor* Ignore, const ETriggerEvent& TriggerEvent)
{
	// Input filter
	if (TriggerEvent == ETriggerEvent::Triggered)
		return false;
	if (TriggerEvent == ETriggerEvent::Completed)
		return false;

	UWorld* World = GetWorld();
	if (!World)
		return false;

	// Line trace
	FVector End = Start + (Direction * Range);
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.TraceTag = TEXT("Shoot trace");
	if (Ignore)
		Params.AddIgnoredActor(Ignore);
	World->LineTraceSingleByChannel(HitResult, Start, End, TraceChannel, Params);

	// Get hit
	AActor* ActorHit = HitResult.GetActor();
	if (!ActorHit)
		return true;

	if (AHLB_Character* Character = Cast<AHLB_Character>(ActorHit))
	{
		Character->HealthComponent->DoDamage(Damage);
	}

	return true;
}