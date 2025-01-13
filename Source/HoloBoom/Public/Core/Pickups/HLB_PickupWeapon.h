// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "Core/Pickups/HLB_Pickup.h"
#include "CoreMinimal.h"

#include "HLB_PickupWeapon.generated.h"

class UHLB_Weapon;

/**
 * Weapon pickup.
 */
UCLASS()
class HOLOBOOM_API AHLB_PickupWeapon : public AHLB_Pickup
{
	GENERATED_BODY()

public:
	virtual void Pick(AHLB_Player* Player) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UHLB_Weapon> Weapon;
};
