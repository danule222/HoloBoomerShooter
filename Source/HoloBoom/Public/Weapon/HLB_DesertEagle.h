// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/HLB_Gun.h"

#include "HLB_DesertEagle.generated.h"

/**
 * Des
 */
UCLASS()
class HOLOBOOM_API UHLB_DesertEagle : public UHLB_Gun
{
	GENERATED_BODY()

protected:
	virtual bool ShootImpl(FVector Start, FVector Direction, AActor* Ignore, const ETriggerEvent& TriggerEvent) override;
};
