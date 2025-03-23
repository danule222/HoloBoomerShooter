// Xarblanca Studios 2025. All rights reserved.

#include "Weapon/HLB_NonGun.h"

#include "Components/SlateWrapperTypes.h"
#include "UI/HUD/HLB_ZombieHUD.h"

void UHLB_NonGun::Initialize(AHLB_ZombieHUD* HUD)
{
	Super::Initialize(HUD);

	HUD->SetAmmoVisibility(ESlateVisibility::Hidden);
}
