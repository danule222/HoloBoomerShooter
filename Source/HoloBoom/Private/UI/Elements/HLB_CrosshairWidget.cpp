// Xarblanca Studios 2025. All rights reserved.

#include "UI/Elements/HLB_CrosshairWidget.h"

#include "Components/Image.h"

void UHLB_CrosshairWidget::SetCrosshair(UTexture2D* Crosshair)
{
	if (Crosshair)
		IMG_Crosshair->SetBrushFromTexture(Crosshair);
	else if (DefaultCrosshair)
	{
		IMG_Crosshair->SetBrushFromTexture(DefaultCrosshair);
		UE_LOG(LogTemp, Warning, TEXT("WEAPON: Null crosshair. Using default one."));
	} 
	else
		UE_LOG(LogTemp, Error, TEXT("WEAPON: Null crosshair & null default crosshair."));
}

void UHLB_CrosshairWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (DefaultCrosshair)
		IMG_Crosshair->SetBrushFromTexture(DefaultCrosshair);
	else
		UE_LOG(LogTemp, Error, TEXT("WEAPON: Null default crosshair."));
}
