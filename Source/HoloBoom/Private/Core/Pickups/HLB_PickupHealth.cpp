// Xarblanca Studios 2025. All rights reserved.

#include "Core/Pickups/HLB_PickupHealth.h"

#include "Characters/Player/HLB_Player.h"
#include "Core/ActorComponents/HLB_HealthComponent.h"

void AHLB_PickupHealth::Pick(AHLB_Player* Player)
{
	if (!Player->HealthComponent)
		return;

	Player->HealthComponent->DoHeal(HealQuantity);

	Destroy();
}