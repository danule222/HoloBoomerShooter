// Xarblanca Studios 2025. All rights reserved.

#include "Characters/Enemies/HLB_EnemyAIController.h"

#include "Kismet/GameplayStatics.h"

void AHLB_EnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	// Player to chase
	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (!PlayerPawn)
		UE_LOG(LogTemp, Error, TEXT("AI: Spawned enemy has no target"));
}

void AHLB_EnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerPawn)
	{
		MoveToActor(PlayerPawn, 100.0f);
	}
}