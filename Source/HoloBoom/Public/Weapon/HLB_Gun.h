// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/HLB_Weapon.h"

#include "HLB_Gun.generated.h"

/**
 * Guns base class.
 */
UCLASS(Abstract)
class HOLOBOOM_API UHLB_Gun : public UHLB_Weapon
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = Statistics, meta = (Units = "seconds"))
	float ReloadTime;

	virtual void PostInitProperties() override;

	virtual void Initialize(AHLB_ZombieHUD* ZHUD) override;

	void Reload();

protected:
	UPROPERTY(EditDefaultsOnly, Category = Ammo, meta = (AllowPrivateAccess = "true"))
	int32 AmmoCapacity;

	UPROPERTY(EditDefaultsOnly, Category = Ammo, meta = (AllowPrivateAccess = "true"))
	int32 MagazineCapacity;

	int32 Ammo;
	int32 Magazines;
	bool bIsReloading;
	FTimerHandle ReloadTimerHandle;

	void FinishReload();

	virtual bool CanShoot() override;
};
