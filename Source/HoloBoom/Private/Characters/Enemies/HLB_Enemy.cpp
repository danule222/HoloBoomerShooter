// Xarblanca Studios 2025. All rights reserved.

#include "Characters/Enemies/HLB_Enemy.h"

#include "Characters/Enemies/HLB_EnemyAIController.h"

// Sets default values
AHLB_Enemy::AHLB_Enemy()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHLB_Enemy::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHLB_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AHLB_Enemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}