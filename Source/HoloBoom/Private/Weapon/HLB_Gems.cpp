// Xarblanca Studios 2025. All rights reserved.

#include "Weapon/HLB_Gems.h"

#include "Camera/CameraComponent.h"
#include "Characters/HLB_Character.h"
#include "Characters/Player/HLB_Player.h"
#include "Core/ActorComponents/HLB_HealthComponent.h"
#include "InputTriggers.h"
#include "UI/HUD/HLB_ZombieHUD.h"

void UHLB_Gems::PostInitProperties()
{
	Super::PostInitProperties();

	Gems = MaxGems;
	bIsShooting = false;
}

void UHLB_Gems::Initialize(AHLB_ZombieHUD* HUD)
{
	Super::Initialize(HUD);

	if (GemsCrosshair.Num() < 4)
	{
		UE_LOG(LogTemp, Error, TEXT("WEAPONS: Gems crosshairs haven't been set up."));
		return;
	}
}

bool UHLB_Gems::ShootImpl(FVector Start, FVector Direction, AActor* Ignore, const ETriggerEvent& TriggerEvent)
{
	// Input filter
	if (TriggerEvent == ETriggerEvent::Triggered)
		return false;
	if (TriggerEvent == ETriggerEvent::Completed)
		return false;

	bIsShooting = true;

	FTimerDelegate TimerDel;
	TimerDel.BindUFunction(this, FName("ShootGem"), Ignore);

	ShootGem(Ignore);
	GetWorld()->GetTimerManager().SetTimer(ShootingTimerHandle, TimerDel, TimeBetweenShoots, true);

	return true;
}

bool UHLB_Gems::CanShoot()
{
	bool Can = Super::CanShoot();

	if (Gems <= 0 || bIsShooting)
		return false;

	return Can;
}

void UHLB_Gems::ShootGem(AActor* Ignore)
{
	// Substract Ammo
	Gems--;

	// Refresh HUD
	ZHUD->SetCrosshair(GemsCrosshair[Gems]);

	UWorld* World = GetWorld();
	if (!World)
		return;
	AHLB_Player* Player = Cast<AHLB_Player>(Ignore);
	if (!Player)
		return;

	// Line trace
	UCameraComponent* Camera = Player->GetFirstPersonCameraComponent();
	FVector Start = Camera->GetComponentLocation();
	FVector Direction = Camera->GetForwardVector();
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
			Character->HealthComponent->DoDamage(Damage);
		}
	}

	if (Gems <= 0)
	{
		World->GetTimerManager().PauseTimer(ShootingTimerHandle);
		World->GetTimerManager().ClearTimer(ShootingTimerHandle);

		GetWorld()->GetTimerManager().SetTimer(ShootingTimerHandle, this, &UHLB_Gems::Reload, TimeToReload, false);
	}
}

void UHLB_Gems::Reload()
{
	bIsShooting = false;

	Gems = MaxGems;
	ZHUD->SetCrosshair(GemsCrosshair[Gems]);
}