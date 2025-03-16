// Xarblanca Studios 2025. All rights reserved.

#include "UI/Elements/HLB_RoundCounterWidget.h"

#include "Components/RichTextBlock.h"

void UHLB_RoundCounterWidget::SetRound(int32 Round)
{
	TXT_Round->SetText(FText::FromString(FString::Printf(TEXT("<Round>%d</>"), Round)));
}