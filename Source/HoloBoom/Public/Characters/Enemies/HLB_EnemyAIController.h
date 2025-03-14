// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "AIController.h"
#include "CoreMinimal.h"

#include "HLB_EnemyAIController.generated.h"

/**
 * Enemy's AI logic
 */
UCLASS()
class HOLOBOOM_API AHLB_EnemyAIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	APawn* PlayerPawn;
};
