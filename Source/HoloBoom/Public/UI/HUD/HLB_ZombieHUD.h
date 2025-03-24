// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "HLB_ZombieHUD.generated.h"

class UHLB_CrosshairWidget;
class UHLB_ZombieHUDWidget;

/**
 * Zombie Game Mode HUD
 */
UCLASS()
class HOLOBOOM_API AHLB_ZombieHUD : public AHUD
{
	GENERATED_BODY()

public:
	// ROUNDS

	void SetRound(int32 Round);

	// CROSSHAIR

	void SetCrosshair(UTexture2D* Crosshair);
	void SetCrosshair(UTexture2D* CrosshairBackground, UTexture2D* CrosshairFill, float Min, float Max);
	void SetCrosshairProgress(float Progress);

	// AMMO

	void SetAmmo(int32 Ammo);
	void SetMagazines(int32 Magazines);
	void SetWeaponName(FText WeaponName);
	void SetAmmoVisibility(ESlateVisibility Visibility);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Widgets, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UHLB_ZombieHUDWidget> ZombieHUDWidgetClass;

	UHLB_ZombieHUDWidget* ZombieHUDWidget;
};
