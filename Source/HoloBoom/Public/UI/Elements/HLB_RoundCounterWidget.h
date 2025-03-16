// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"

#include "HLB_RoundCounterWidget.generated.h"

class URichTextBlock;

/**
 * Round counter widget
 */
UCLASS()
class HOLOBOOM_API UHLB_RoundCounterWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetRound(int32 Round);

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true"))
	URichTextBlock* TXT_Round;
};
