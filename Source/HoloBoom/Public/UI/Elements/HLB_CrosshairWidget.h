// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"

#include "HLB_CrosshairWidget.generated.h"

class UImage;

/**
 * Weapon's crosshair widget
 */
UCLASS()
class HOLOBOOM_API UHLB_CrosshairWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetCrosshair(UTexture2D* Crosshair);

protected:
	virtual void NativePreConstruct() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true"))
	UImage* IMG_Crosshair;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Crosshair, meta = (AllowPrivateAccess = "true"))
	UTexture2D* DefaultCrosshair;
};
