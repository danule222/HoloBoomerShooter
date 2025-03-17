// Xarblanca Studios 2025. All rights reserved.

#include "Weapon/HLB_Weapon.h"

#include "Characters/HLB_Character.h"
#include "Core/GameFramework/HLB_Globals.h"
#include "Core/ActorComponents/HLB_HealthComponent.h"

void UHLB_Weapon::Shoot(FVector Start, FVector Direction, AActor* Ignore)
{
	UE_LOG(LogTemp, Display, TEXT("WEAPONS: Pium - %s weapon"), *Name.ToString());

	if (UWorld* World = GetWorld())
	{
		FVector End = Start + (Direction * Range);

		FHitResult HitResult;
		FCollisionQueryParams Params;
		Params.TraceTag = TEXT("Shoot trace");

		if (Ignore)
			Params.AddIgnoredActor(Ignore);

		World->LineTraceSingleByChannel(HitResult, Start, End, TraceChannel, Params);

		AActor* ActorHit = HitResult.GetActor();

		if (!ActorHit)
			return;

		if (AHLB_Character* Character = Cast<AHLB_Character>(ActorHit))
		{
			Character->HealthComponent->DoDamage(Damage);
		}
	}
}