// Xarblanca Studios 2025. All rights reserved.

#include "UI/Elements/HLB_CrosshairWidget.h"

#include "Components/Image.h"
#include "Components/ProgressBar.h"
#include "Components/WidgetSwitcher.h"

void UHLB_CrosshairWidget::SetCrosshair(UTexture2D* Crosshair)
{
	WS_Switcher->SetActiveWidgetIndex(0);

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

void UHLB_CrosshairWidget::SetCrosshair(UTexture2D* CrosshairBackground, UTexture2D* CrosshairFill, float Min, float Max)
{
	WS_Switcher->SetActiveWidgetIndex(1);

	FProgressBarStyle ProgressBarStyle = PB_Crosshair->GetWidgetStyle();

	if (CrosshairBackground)
	{
		FSlateBrush BackgroundBrush;
		BackgroundBrush.SetResourceObject(CrosshairBackground);
		BackgroundBrush.DrawAs = ESlateBrushDrawType::Image;
		BackgroundBrush.ImageSize = FVector2D(CrosshairBackground->GetSizeX(), CrosshairBackground->GetSizeY());
		ProgressBarStyle.SetBackgroundImage(BackgroundBrush);
	}
	
	if (CrosshairFill)
	{
		FSlateBrush FillBrush;
		FillBrush.SetResourceObject(CrosshairFill);
		FillBrush.DrawAs = ESlateBrushDrawType::Image;
		FillBrush.ImageSize = FVector2D(CrosshairFill->GetSizeX(), CrosshairFill->GetSizeY());
		ProgressBarStyle.SetFillImage(FillBrush);
	}
	

	PB_Crosshair->SetWidgetStyle(ProgressBarStyle);

	MinProgressBar = Min;
	MaxProgressBar = Max;
}

void UHLB_CrosshairWidget::SetCrosshairProgress(float Progress)
{
	PB_Crosshair->SetPercent(
		FMath::GetMappedRangeValueClamped(FVector2D(0.f, 1.f), FVector2D(MinProgressBar, MaxProgressBar), Progress));
}

void UHLB_CrosshairWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (DefaultCrosshair)
		IMG_Crosshair->SetBrushFromTexture(DefaultCrosshair);
	else
		UE_LOG(LogTemp, Error, TEXT("WEAPON: Null default crosshair."));
}