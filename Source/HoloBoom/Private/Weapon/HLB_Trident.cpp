// Xarblanca Studios 2025. All rights reserved.

#include "Weapon/HLB_Trident.h"

#include "Characters/HLB_Character.h"
#include "Core/ActorComponents/HLB_HealthComponent.h"
#include "InputTriggers.h"
#include "UI/HUD/HLB_ZombieHUD.h"

void UHLB_Trident::Initialize(AHLB_ZombieHUD* HUD)
{
	Super::Initialize(HUD);

	Charge = 0.f;
	bIsStartingToCharge = true;
	bCanShoot = true;

	ZHUD->SetCrosshair(CrosshairBackground, CrosshairFill, ChargeMinProgressBar, ChargeMaxProgressBar);
	ZHUD->SetCrosshairProgress(0.f);
}

bool UHLB_Trident::ShootImpl(FVector Start, FVector Direction, AActor* Ignore, const ETriggerEvent& TriggerEvent)
{
	bool DidShoot = false;

	switch (TriggerEvent)
	{
		case ETriggerEvent::Started:
		case ETriggerEvent::Triggered:
		{
			// Check if charge is complete
			if (Charge >= 1.f)
				break;

			UWorld* World = GetWorld();
			if (!World)
				break;

			if (bIsStartingToCharge)
			{
				LastChargeTime = World->GetTimeSeconds();
				bIsStartingToCharge = false;

				break;
			}

			float Delta = World->GetTimeSeconds() - LastChargeTime;
			LastChargeTime = World->GetTimeSeconds();

			Charge += Delta * ChargePerSecond;
			if (Charge > 1.f)
			{
				Charge = 1.f;
				ZHUD->SetCrosshair(CrosshairChargeComplete);
			}

			ZHUD->SetCrosshairProgress(Charge);

			break;
		}
		case ETriggerEvent::Completed:
			Shoot(Start, Direction, Ignore, TriggerEvent);
			DidShoot = true;

			break;
	}

	return DidShoot;
}

bool UHLB_Trident::CanShoot()
{
	bool Can = Super::CanShoot();

	return Can && bCanShoot;
}

void UHLB_Trident::Shoot(FVector Start, FVector Direction, AActor* Ignore, const ETriggerEvent& TriggerEvent)
{
	UWorld* World = GetWorld();
	if (!World)
		return;

	// Line trace
	FVector End = Start + (Direction * (Range * DistanceMultiplierCurve.GetRichCurve()->Eval(Charge)));
	TArray<FHitResult> HitResults;
	FCollisionQueryParams Params;
	Params.TraceTag = TEXT("Shoot trace");
	if (Ignore)
		Params.AddIgnoredActor(Ignore);
	World->LineTraceMultiByChannel(HitResults, Start, End, TraceChannel, Params);

	// Get hit
	for (const FHitResult& Hit : HitResults)
	{
		AActor* ActorHit = Hit.GetActor();
		if (ActorHit)
		{
			if (AHLB_Character* Character = Cast<AHLB_Character>(ActorHit))
			{
				Character->HealthComponent->DoDamage(Damage * DamageMultiplierCurve.GetRichCurve()->Eval(Charge));
			}
		}
	}

	Charge = 0.f;
	ZHUD->SetCrosshair(CrosshairCantShoot);
	World->GetTimerManager().SetTimer(
		EnableShootCrosshairTimer, this, &UHLB_Trident::EnableShootCrosshair, TimeBetweenShoots, false);
	bCanShoot = false;
}

void UHLB_Trident::EnableShootCrosshair()
{
	if (bIsStartingToCharge)
		return;

	ZHUD->SetCrosshair(CrosshairBackground, CrosshairFill, ChargeMinProgressBar, ChargeMaxProgressBar);
	ZHUD->SetCrosshairProgress(Charge);

	bIsStartingToCharge = true;
	bCanShoot = true;
}