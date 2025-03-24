// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/HLB_NonGun.h"

#include "HLB_Trident.generated.h"

/**
 * Trident weapon.
 */
UCLASS()
class HOLOBOOM_API UHLB_Trident : public UHLB_NonGun
{
	GENERATED_BODY()

public:
	virtual void Initialize(AHLB_ZombieHUD* ZHUD) override;

protected:
	virtual bool ShootImpl(FVector Start, FVector Direction, AActor* Ignore, const ETriggerEvent& TriggerEvent);

	virtual bool CanShoot() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = Aspect, meta = (AllowPrivateAccess = "true"))
	UTexture2D* CrosshairBackground;

	UPROPERTY(EditDefaultsOnly, Category = Aspect, meta = (AllowPrivateAccess = "true"))
	UTexture2D* CrosshairFill;

	UPROPERTY(EditDefaultsOnly, Category = Aspect, meta = (AllowPrivateAccess = "true"))
	UTexture2D* CrosshairChargeComplete;

	UPROPERTY(EditDefaultsOnly, Category = Aspect, meta = (AllowPrivateAccess = "true"))
	UTexture2D* CrosshairCantShoot;

	UPROPERTY(EditDefaultsOnly, Category = Statistics, meta = (AllowPrivateAccess = "true"))
	float ChargeMinProgressBar;

	UPROPERTY(EditDefaultsOnly, Category = Statistics, meta = (AllowPrivateAccess = "true"))
	float ChargeMaxProgressBar;

	UPROPERTY(EditDefaultsOnly, Category = Statistics, meta = (AllowPrivateAccess = "true"))
	float ChargePerSecond;

	UPROPERTY(EditDefaultsOnly, Category = Statistics, meta = (AllowPrivateAccess = "true"))
	FRuntimeFloatCurve DamageMultiplierCurve;

	UPROPERTY(EditDefaultsOnly, Category = Statistics, meta = (AllowPrivateAccess = "true"))
	FRuntimeFloatCurve DistanceMultiplierCurve;

	float Charge;
	float LastChargeTime;
	bool bIsStartingToCharge;
	bool bCanShoot;
	FTimerHandle EnableShootCrosshairTimer;

	void Shoot(FVector Start, FVector Direction, AActor* Ignore, const ETriggerEvent& TriggerEvent);
	void EnableShootCrosshair();
};
