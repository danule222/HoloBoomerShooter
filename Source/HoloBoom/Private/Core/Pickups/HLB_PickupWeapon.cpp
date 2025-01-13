// Xarblanca Studios 2025. All rights reserved.

#include "Core/Pickups/HLB_PickupWeapon.h"

#include "Player/HLB_Player.h"
#include "Weapon/HLB_Weapon.h"
#include "Weapon/HLB_WeaponComponent.h"

void AHLB_PickupWeapon::Pick(AHLB_Player* Player)
{
	if (*Weapon)
	{
		UHLB_Weapon* WeaponObj = NewObject<UHLB_Weapon>(this, Weapon);
		Player->WeaponComponent->SetWeapon(WeaponObj);
	}
}