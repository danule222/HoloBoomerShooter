// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"

#include "HLB_AmmoWidget.generated.h"

class URichTextBlock;

/**
 * Ammo widget
 */
UCLASS()
class HOLOBOOM_API UHLB_AmmoWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetAmmo(int32 Ammo);
	void SetMagazines(int32 Magazines);
	void SetWeaponName(FText WeaponName);
	void SetVisibility(ESlateVisibility Visibility) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true"))
	URichTextBlock* TXT_Ammo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true"))
	URichTextBlock* TXT_Magazines;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true"))
	URichTextBlock* TXT_WeaponName;
};
