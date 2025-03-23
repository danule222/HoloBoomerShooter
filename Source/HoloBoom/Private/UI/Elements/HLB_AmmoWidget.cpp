// Xarblanca Studios 2025. All rights reserved.

#include "UI/Elements/HLB_AmmoWidget.h"

#include "Components/RichTextBlock.h"

void UHLB_AmmoWidget::SetAmmo(int32 Ammo)
{
	TXT_Ammo->SetText(FText::FromString(FString::Printf(TEXT("<Ammo>%d</>"), Ammo)));
}

void UHLB_AmmoWidget::SetMagazines(int32 Magazines)
{
	TXT_Magazines->SetText(FText::FromString(FString::Printf(TEXT("<Magazines>%02d</>"), Magazines)));
}

void UHLB_AmmoWidget::SetWeaponName(FText WeaponName)
{
	TXT_WeaponName->SetText(FText::FromString(FString::Printf(TEXT("<WeaponName>%s</>"), *WeaponName.ToString())));
}

void UHLB_AmmoWidget::SetVisibility(ESlateVisibility Vsblty)
{
	switch (Vsblty)
	{
		case ESlateVisibility::Visible:
			Super::SetVisibility(Vsblty);
			break;
		case ESlateVisibility::Hidden:
			Super::SetVisibility(Vsblty);
			break;
	}
}
