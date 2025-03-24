// Xarblanca Studios 2025. All rights reserved.

#include "Weapon/HLB_Gun.h"

#include "Components/SlateWrapperTypes.h"
#include "UI/HUD/HLB_ZombieHUD.h"

void UHLB_Gun::PostInitProperties()
{
	Super::PostInitProperties();

	LastShootTime = -TimeBetweenShoots;
	bIsReloading = false;

	Ammo = AmmoCapacity;
	Magazines = MagazineCapacity;
}

void UHLB_Gun::Initialize(AHLB_ZombieHUD* HUD)
{
	Super::Initialize(HUD);

	HUD->SetAmmoVisibility(ESlateVisibility::Visible);
	HUD->SetAmmo(Ammo);
	HUD->SetMagazines(Magazines);
	ZHUD->SetWeaponName(Name);
}

void UHLB_Gun::Reload()
{
	if (Magazines <= 0)
		return;

	bIsReloading = true;
	Magazines--;

	ZHUD->SetMagazines(Magazines);

	GetWorld()->GetTimerManager().SetTimer(ReloadTimerHandle, this, &UHLB_Gun::FinishReload, ReloadTime, false);
}

void UHLB_Gun::FinishReload()
{
	Ammo = AmmoCapacity;

	ZHUD->SetAmmo(Ammo);

	bIsReloading = false;
}

bool UHLB_Gun::CanShoot()
{
	bool Can = Super::CanShoot();

	if (Ammo <= 0 || bIsReloading)
		return false;

	return Can;
}