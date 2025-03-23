// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "HLB_Weapon.generated.h"

class UTexture2D;
class UStaticMesh;
class AHLB_ZombieHUD;

enum class ETriggerEvent : uint8;

/**
 * Weapons base class.
 */
UCLASS(Abstract)
class HOLOBOOM_API UHLB_Weapon : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = Aspect)
	UStaticMesh* Mesh;

	UPROPERTY(EditDefaultsOnly, Category = Aspect)
	UTexture2D* DefaultCrosshair;

	UPROPERTY(EditDefaultsOnly, Category = General)
	FText Name;

	UPROPERTY(EditDefaultsOnly, Category = Statistics)
	int32 Damage;

	UPROPERTY(EditDefaultsOnly, Category = Statistics, meta = (Units = "centimeters"))
	int32 Range;

	UPROPERTY(EditDefaultsOnly, Category = Statistics, meta = (Units = "seconds"))
	float TimeBetweenShoots;

	UPROPERTY(EditDefaultsOnly, Category = Functionality)
	TEnumAsByte<ECollisionChannel> TraceChannel;

	virtual void Initialize(AHLB_ZombieHUD* ZHUD);

	void Shoot(FVector Start, FVector Direction, AActor* Ignore, const ETriggerEvent& TriggerEvent);

protected:
	/**
	 * Implementation of the shoot function.
	 *
	 * \return True if the shoot has been fired, False if not.
	 */
	virtual bool ShootImpl(FVector Start, FVector Direction, AActor* Ignore, const ETriggerEvent& TriggerEvent);

	virtual bool CanShoot();

protected:
	float LastShootTime;
	AHLB_ZombieHUD* ZHUD;
};
