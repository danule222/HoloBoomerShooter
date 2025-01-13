// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "HLB_Weapon.generated.h"

class UTexture2D;
class UStaticMesh;

/**
Weapons base class.
 */
UCLASS(Blueprintable, BlueprintType)
class HOLOBOOM_API UHLB_Weapon : public UObject
{
	GENERATED_BODY()

public:
	UHLB_Weapon();
	~UHLB_Weapon();

	void Shoot();

private:
	UPROPERTY(EditDefaultsOnly)
	UStaticMesh* Mesh;
	UPROPERTY(EditDefaultsOnly)
	FText Name;
	UPROPERTY(EditDefaultsOnly)
	int32 Damage;
	UPROPERTY(EditDefaultsOnly)
	int32 Range;
	UPROPERTY(EditDefaultsOnly)
	int32 Speed;
	UPROPERTY(EditDefaultsOnly)
	UTexture2D* Crosshair;
};
