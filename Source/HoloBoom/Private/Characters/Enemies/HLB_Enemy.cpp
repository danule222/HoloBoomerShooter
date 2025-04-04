// Xarblanca Studios 2025. All rights reserved.

#include "Characters/Enemies/HLB_Enemy.h"

#include "Characters/Enemies/HLB_EnemyAIController.h"
#include "Core/ActorComponents/HLB_HealthComponent.h"
#include "Core/GameFramework/HLB_Globals.h"
#include "Core/GameModes/HLB_ZombieGameMode.h"
#include "Kismet/GameplayStatics.h"

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

void AHLB_Enemy::PostInitProperties()
{
	Super::PostInitProperties();

	Tags.Add(TAG_ENEMY);
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

void AHLB_Enemy::Die()
{
	AGameModeBase* GameMode = UGameplayStatics::GetGameMode(GetWorld());
	if (AHLB_ZombieGameMode* ZombieGameMode = Cast<AHLB_ZombieGameMode>(GameMode))
	{
		ZombieGameMode->EnemyKilled(this);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ENEMIES: Enemy is not in a Zombie Game Mode"));
	}
}