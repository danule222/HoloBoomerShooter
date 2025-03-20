// Xarblanca Studios 2025. All rights reserved.

#include "UI/HUD/HLB_ZombieHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Elements/HLB_AmmoWidget.h"
#include "UI/Elements/HLB_CrosshairWidget.h"
#include "UI/Elements/HLB_RoundCounterWidget.h"
#include "UI/HUD/HLB_ZombieHUDWidget.h"

void AHLB_ZombieHUD::SetRound(int32 Round)
{
	ZombieHUDWidget->RoundCounter->SetRound(Round);
}

void AHLB_ZombieHUD::SetCrosshair(UTexture2D* Crosshair)
{
	ZombieHUDWidget->Crosshair->SetCrosshair(Crosshair);
}

void AHLB_ZombieHUD::SetAmmo(int32 Ammo)
{
	ZombieHUDWidget->Ammo->SetAmmo(Ammo);
}

void AHLB_ZombieHUD::SetMagazines(int32 Magazines)
{
	ZombieHUDWidget->Ammo->SetMagazines(Magazines);
}

void AHLB_ZombieHUD::SetWeaponName(FText WeaponName)
{
	ZombieHUDWidget->Ammo->SetWeaponName(WeaponName);
}

void AHLB_ZombieHUD::BeginPlay()
{
	Super::BeginPlay();

	// Create widgets
	if (UWorld* World = GetWorld())
	{
		ZombieHUDWidget = CreateWidget<UHLB_ZombieHUDWidget>(World, ZombieHUDWidgetClass, TEXT("ZombieHUDWidget"));
	}

	// Add to viewport
	if (ZombieHUDWidget)
		ZombieHUDWidget->AddToViewport();
}