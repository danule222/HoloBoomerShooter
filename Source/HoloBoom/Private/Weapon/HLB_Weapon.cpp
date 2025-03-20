// Xarblanca Studios 2025. All rights reserved.

#include "Weapon/HLB_Weapon.h"

#include "Characters/HLB_Character.h"
#include "Core/ActorComponents/HLB_HealthComponent.h"
#include "Core/GameFramework/HLB_Globals.h"
#include "InputTriggers.h"
#include "UI/HUD/HLB_ZombieHUD.h"

void UHLB_Weapon::PostInitProperties()
{
	Super::PostInitProperties();

	LastShootTime = -TimeBetweenShoots;
	bIsReloading = false;

	Ammo = AmmoCapacity;
	Magazines = MagazineCapacity;
}

void UHLB_Weapon::Initialize(AHLB_ZombieHUD* HUD)
{
	if (!HUD)
		return;

	ZHUD = HUD;

	ZHUD->SetAmmo(Ammo);
	ZHUD->SetMagazines(Magazines);
	ZHUD->SetCrosshair(DefaultCrosshair);
	ZHUD->SetWeaponName(Name);
}

void UHLB_Weapon::Shoot(FVector Start, FVector Direction, AActor* Ignore, const ETriggerEvent& TriggerEvent)
{
	if (!CanShoot())
		return;

	bool DidShoot = ShootImpl(Start, Direction, Ignore, TriggerEvent);

	if (DidShoot)
	{
		LastShootTime = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Display, TEXT("WEAPONS: Pium - %s weapon"), *Name.ToString());
	}
}

void UHLB_Weapon::Reload()
{
	if (Magazines <= 0)
		return;

	bIsReloading = true;
	Magazines--;

	ZHUD->SetMagazines(Magazines);

	GetWorld()->GetTimerManager().SetTimer(ReloadTimerHandle, this, &UHLB_Weapon::FinishReload, ReloadTime, false);
}

bool UHLB_Weapon::ShootImpl(FVector Start, FVector Direction, AActor* Ignore, const ETriggerEvent& TriggerEvent)
{
	UE_LOG(LogTemp, Error, TEXT("WEAPONS: %s's shoot not implemented."), *Name.ToString());

	return false;
}

bool UHLB_Weapon::CanShoot()
{
	if (Ammo <= 0 || bIsReloading)
		return false;

	float CurrentTime = GetWorld()->GetTimeSeconds();

	if (CurrentTime - LastShootTime >= TimeBetweenShoots)
		return true;
	else
		return false;
}

void UHLB_Weapon::FinishReload()
{
	Ammo = AmmoCapacity;

	ZHUD->SetAmmo(Ammo);

	bIsReloading = false;
}
