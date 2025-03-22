// Xarblanca Studios 2025. All rights reserved.

#include "Weapon/HLB_AA12.h"

#include "Characters/HLB_Character.h"
#include "Core/ActorComponents/HLB_HealthComponent.h"
#include "InputTriggers.h"
#include "UI/HUD/HLB_ZombieHUD.h"

void UHLB_AA12::Initialize(AHLB_ZombieHUD* HUD)
{
	Super::Initialize(HUD);

	if (DiceCrosshair.Num() < 6)
	{
		UE_LOG(LogTemp, Error, TEXT("WEAPONS: Dice crosshairs haven't been set up."));
		return;
	}

	// Dice number
	Dice = FMath::RandRange(1, 6);
	HUD->SetCrosshair(DiceCrosshair[Dice - 1]);
}

bool UHLB_AA12::ShootImpl(FVector Start, FVector Direction, AActor* Ignore, const ETriggerEvent& TriggerEvent)
{
	// Input filter
	if (TriggerEvent == ETriggerEvent::Completed)
		return false;

	// Substract Ammo
	Ammo--;

	// Refresh HUD
	ZHUD->SetAmmo(Ammo);

	UWorld* World = GetWorld();
	if (!World)
		return false;

	// Damage
	int32 ActualDamage = Damage;
	if (Dice == 1)
		ActualDamage *= DiceOneMultiplier;
	else
		ActualDamage /= Dice;

	UE_LOG(LogTemp, Warning, TEXT("%d"), ActualDamage);

	// Line trace
	if (Dice == 1)
	{
		FVector End = Start + (Direction * Range);
		FHitResult HitResult;
		FCollisionQueryParams Params;
		Params.TraceTag = TEXT("Shoot trace");
		if (Ignore)
			Params.AddIgnoredActor(Ignore);
		World->LineTraceSingleByChannel(HitResult, Start, End, TraceChannel, Params);

		// Get hit
		AActor* ActorHit = HitResult.GetActor();
		if (ActorHit)
		{
			if (AHLB_Character* Character = Cast<AHLB_Character>(ActorHit))
			{
				Character->HealthComponent->DoDamage(ActualDamage);
			}
		}
	}
	else
	{
		for (int32 i = 0; i < Dice; i++)
		{
			FVector End = Start + (Direction * Range);

			End += FVector(FMath::RandRange(-GunDispersion, GunDispersion), FMath::RandRange(-GunDispersion, GunDispersion),
				FMath::RandRange(-GunDispersion, GunDispersion));

			FHitResult HitResult;
			FCollisionQueryParams Params;
			Params.TraceTag = TEXT("Shoot trace");
			if (Ignore)
				Params.AddIgnoredActor(Ignore);
			World->LineTraceSingleByChannel(HitResult, Start, End, TraceChannel, Params);

			// Get hit
			AActor* ActorHit = HitResult.GetActor();
			if (ActorHit)
			{
				if (AHLB_Character* Character = Cast<AHLB_Character>(ActorHit))
				{
					Character->HealthComponent->DoDamage(ActualDamage);
				}
			}
		}
	}

	// Dice number
	Dice = FMath::RandRange(1, 6);
	ZHUD->SetCrosshair(DiceCrosshair[Dice - 1]);

	return true;
}