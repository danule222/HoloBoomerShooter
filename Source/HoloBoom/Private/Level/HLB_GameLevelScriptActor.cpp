// Xarblanca Studios 2025. All rights reserved.

#include "Level/HLB_GameLevelScriptActor.h"

#include "Kismet/GameplayStatics.h"

void AHLB_GameLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Display, TEXT("LEVEL: Level %s started"), *UGameplayStatics::GetCurrentLevelName(GetWorld()));


}