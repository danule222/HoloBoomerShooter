// Xarblanca Studios 2025. All rights reserved.

#include "Core/Pickups/HLB_PickupHealth.h"

#include "Core/ActorComponents/HLB_HealthComponent.h"
#include "Player/HLB_Player.h"

void AHLB_PickupHealth::Pick(AHLB_Player* Player)
{
	if (!Player->HealthComponent)
		return;
	
	Player->HealthComponent->DoHeal(HealQuantity);

	Destroy();
}