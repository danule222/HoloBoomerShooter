// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/HLB_NonGun.h"

#include "HLB_Gems.generated.h"

/**
 * Gems weapon.
 */
UCLASS()
class HOLOBOOM_API UHLB_Gems : public UHLB_NonGun
{
	GENERATED_BODY()

public:
	virtual void PostInitProperties() override;

	virtual void Initialize(AHLB_ZombieHUD* ZHUD) override;

protected:
	virtual bool ShootImpl(FVector Start, FVector Direction, AActor* Ignore, const ETriggerEvent& TriggerEvent) override;

	virtual bool CanShoot() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = Ammo, meta = (AllowPrivateAccess = "true"))
	int32 MaxGems;

	UPROPERTY(EditDefaultsOnly, Category = Aspect, meta = (AllowPrivateAccess = "true"))
	TArray<UTexture2D*> GemsCrosshair;

	UPROPERTY(EditDefaultsOnly, Category = Ammo, meta = (AllowPrivateAccess = "true", Units = "seconds"))
	float TimeToReload;

	int32 Gems;
	bool bIsShooting;
	FTimerHandle ShootingTimerHandle;
	FTimerHandle ReloadTimerHandle;

	UFUNCTION()
	void ShootGem(AActor* Ignore);

	void Reload();
};
