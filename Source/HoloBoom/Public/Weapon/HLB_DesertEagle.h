// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/HLB_Weapon.h"

#include "HLB_DesertEagle.generated.h"

/**
 * Des
 */
UCLASS()
class HOLOBOOM_API UHLB_DesertEagle : public UHLB_Weapon
{
	GENERATED_BODY()

protected:
	virtual bool ShootImpl(FVector Start, FVector Direction, AActor* Ignore, const ETriggerEvent& TriggerEvent) override;
};
