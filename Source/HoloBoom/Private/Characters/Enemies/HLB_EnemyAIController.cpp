// Xarblanca Studios 2025. All rights reserved.

#include "Characters/Enemies/HLB_EnemyAIController.h"

#include "Kismet/GameplayStatics.h"

void AHLB_EnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	// Player to chase
	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
}

void AHLB_EnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerPawn)
	{					     // Tolerance
		MoveToActor(PlayerPawn, 100.0f);
	}
}