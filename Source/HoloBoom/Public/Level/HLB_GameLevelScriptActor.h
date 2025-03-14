// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"

#include "HLB_GameLevelScriptActor.generated.h"

/**
 * Script that manages level in play mode
 */
UCLASS()
class HOLOBOOM_API AHLB_GameLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
};
