// Xarblanca Studios 2025. All rights reserved.

#include "Weapon/HLB_Weapon.h"

UHLB_Weapon::UHLB_Weapon()
{
}

UHLB_Weapon::~UHLB_Weapon()
{
}

void UHLB_Weapon::Shoot(FVector Start, FVector Direction, AActor* Ignore)
{
	UE_LOG(LogTemp, Warning, TEXT("Pium - %s"), *Name.ToString());

	if (UWorld *World = GetWorld())
	{
		FVector End = Start + (Direction * Range);

		FHitResult HitResult;
		FCollisionQueryParams Params;
		Params.TraceTag = TEXT("Shoot trace");
		
		if (Ignore)
			Params.AddIgnoredActor(Ignore);

		World->LineTraceSingleByChannel(HitResult, Start, End, TraceChannel, Params);

		// TODO: Check if enemy was hit
	}
}
