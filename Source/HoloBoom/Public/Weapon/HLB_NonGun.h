// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/HLB_Weapon.h"

#include "HLB_NonGun.generated.h"

/**
 * Non Guns base class.
 */
UCLASS()
class HOLOBOOM_API UHLB_NonGun : public UHLB_Weapon
{
	GENERATED_BODY()

public:
	virtual void Initialize(AHLB_ZombieHUD* ZHUD) override;
};
