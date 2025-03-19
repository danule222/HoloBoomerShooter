// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "HLB_Weapon.generated.h"

class UTexture2D;
class UStaticMesh;

enum class ETriggerEvent : uint8;

/**
 * Weapons base class.
 */
UCLASS(Blueprintable, BlueprintType)
class HOLOBOOM_API UHLB_Weapon : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	UStaticMesh* Mesh;

	UPROPERTY(EditDefaultsOnly)
	FText Name;

	UPROPERTY(EditDefaultsOnly)
	int32 Damage;

	UPROPERTY(EditDefaultsOnly, meta = (Units = "centimeters"))
	int32 Range;

	UPROPERTY(EditDefaultsOnly, meta = (Units = "seconds"))
	float TimeBetweenShoots;

	UPROPERTY(EditDefaultsOnly, meta = (Units = "seconds"))
	float ReloadTime;

	UPROPERTY(EditDefaultsOnly)
	UTexture2D* DefaultCrosshair;

	UPROPERTY(EditDefaultsOnly)
	TEnumAsByte<ECollisionChannel> TraceChannel;

	virtual void PostInitProperties() override;

	void Shoot(FVector Start, FVector Direction, AActor* Ignore, const ETriggerEvent& TriggerEvent);

protected:
	/**
	 * Implementation of the shoot function.
	 * 
	 * \return True if the shoot has been fired, False if not.
	 */
	virtual bool ShootImpl(FVector Start, FVector Direction, AActor* Ignore, const ETriggerEvent& TriggerEvent);

	bool CanShoot();

private:
	float LastShootTime;
};
