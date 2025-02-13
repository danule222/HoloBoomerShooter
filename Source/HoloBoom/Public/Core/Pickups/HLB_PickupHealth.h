// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "Core/Pickups/HLB_Pickup.h"
#include "CoreMinimal.h"

#include "HLB_PickupHealth.generated.h"

/**
 * Health pickup.
 */
UCLASS()
class HOLOBOOM_API AHLB_PickupHealth : public AHLB_Pickup
{
	GENERATED_BODY()

public:
	virtual void Pick(AHLB_Player* Player) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	int32 HealQuantity;
};
