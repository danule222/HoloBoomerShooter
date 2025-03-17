// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"

#include "HLB_ZombieHUDWidget.generated.h"

class UHLB_CrosshairWidget;
class UHLB_RoundCounterWidget;

/**
 * Main Widget used by Zombie HUD
 */
UCLASS()
class HOLOBOOM_API UHLB_ZombieHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UHLB_RoundCounterWidget* RoundCounter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UHLB_CrosshairWidget* Crosshair;
};
