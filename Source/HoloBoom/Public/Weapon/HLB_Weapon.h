// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "HLB_Weapon.generated.h"

class UTexture2D;
class UStaticMesh;

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

	virtual void Shoot(FVector Start, FVector Direction, AActor* Ignore);
};
