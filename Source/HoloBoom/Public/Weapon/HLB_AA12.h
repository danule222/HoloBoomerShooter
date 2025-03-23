// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/HLB_Gun.h"

#include "HLB_AA12.generated.h"

/**
 * AA12 weapon
 */
UCLASS()
class HOLOBOOM_API UHLB_AA12 : public UHLB_Gun
{
	GENERATED_BODY()

public:
	virtual void Initialize(AHLB_ZombieHUD* ZHUD);

protected:
	virtual bool ShootImpl(FVector Start, FVector Direction, AActor* Ignore, const ETriggerEvent& TriggerEvent);

private:
	UPROPERTY(EditDefaultsOnly, Category = Ammo, meta = (AllowPrivateAccess = "true", Units = "centimeters"))
	float GunDispersion;

	UPROPERTY(EditDefaultsOnly, Category = Ammo, meta = (AllowPrivateAccess = "true"))
	float DiceOneMultiplier;

	UPROPERTY(EditDefaultsOnly, Category = Aspect, meta = (AllowPrivateAccess = "true"))
	TArray<UTexture2D*> DiceCrosshair;

	int32 Dice;
};
