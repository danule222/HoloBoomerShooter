// Xarblanca Studios 2025. All rights reserved.

#include "Core/GameModes/HLB_ZombieGameMode.h"

#include "Characters/Enemies/HLB_Enemy.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Placeables/Placements/HLB_EnemySpawner.h"

void AHLB_ZombieGameMode::RegisterSpawner(AHLB_EnemySpawner* Spawner)
{
	Spawners.Add(Spawner);

	UE_LOG(LogTemp, Display, TEXT("SPAWNERS: %s registered"), *Spawner->GetName());
}

void AHLB_ZombieGameMode::EnemyKilled(AHLB_Enemy* Enemy)
{
	if (Enemy)
	{
		Enemy->SetActorHiddenInGame(true);
		Enemy->SetActorEnableCollision(false);
		Enemy->GetCharacterMovement()->GravityScale = 0.f;
		Enemy->SetActorTickEnabled(false);
		Enemy->GetController()->SetActorTickEnabled(false);

		EnemyPool.Add(Enemy);
	}

	if (++KilledEnemies >= InitialEnemies)
	{
		NewRound();
	}
}

void AHLB_ZombieGameMode::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Display, TEXT("GAME MODE: Zombie game mode started"));
	UE_LOG(LogTemp, Display, TEXT("SPAWNERS: %d spawners registered"), Spawners.Num());

	SetRounds();
	SetPool();
	SetSpawners();
}

void AHLB_ZombieGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	GetWorld()->GetTimerManager().ClearTimer(SpawnerTimerHandle);
}

void AHLB_ZombieGameMode::SetRounds()
{
	ActualRound = 1;
	EnemiesSpawnedThisRound = 0;
}

void AHLB_ZombieGameMode::NewRound()
{
	UE_LOG(LogTemp, Display, TEXT("ROUNDS: Round %d finished"), ActualRound);

	ActualRound++;
	EnemiesSpawnedThisRound = 0;
	KilledEnemies = 0;
	InitialEnemies += NewEnemiesPerRound;

	// Start new round timer
	GetWorld()->GetTimerManager().SetTimer(NewRoundTimerHandle, this, &AHLB_ZombieGameMode::StartNewRound, TimeBetweenRounds, false);
}

void AHLB_ZombieGameMode::StartNewRound()
{
	SetSpawners();

	UE_LOG(LogTemp, Display, TEXT("ROUNDS: Round %d started"), ActualRound);
}

void AHLB_ZombieGameMode::SpawnEnemy()
{
	if (EnemiesSpawnedThisRound + 1 > InitialEnemies)
	{
		// Stop spawner timer
		GetWorld()->GetTimerManager().PauseTimer(SpawnerTimerHandle);
		GetWorld()->GetTimerManager().ClearTimer(SpawnerTimerHandle);

		return;
	}

	if (EnemyPool.Num() <= 0)
		return;	   // No more enemies in pool

	// Select spawner
	AHLB_EnemySpawner* Spawner = Spawners[FMath::RandRange(0, Spawners.Num() - 1)];

	// Extract enemy from pool
	AHLB_Enemy* Enemy = EnemyPool.Pop();

	// Spawn enemy
	Spawner->Spawn(Enemy);
	EnemiesSpawnedThisRound++;
}

void AHLB_ZombieGameMode::SetSpawners()
{
	GetWorld()->GetTimerManager().SetTimer(SpawnerTimerHandle, this, &AHLB_ZombieGameMode::SpawnEnemy, TimeBetweenSpawns, true);
}

void AHLB_ZombieGameMode::SetPool()
{
	// Enemies

	for (int32 i = 0; i < MaxNumOfEnemies; i++)
	{
		AHLB_Enemy* NewActor = GetWorld()->SpawnActor<AHLB_Enemy>(EnemyClass);
		if (NewActor)
		{
			NewActor->SetActorHiddenInGame(true);
			NewActor->SetActorEnableCollision(false);
			NewActor->GetCharacterMovement()->GravityScale = 0.f;
			NewActor->SetActorTickEnabled(false);
			NewActor->GetController()->SetActorTickEnabled(false);

			EnemyPool.Add(NewActor);
		}
	}

	if (!EnemyPool.Num())
	{
		UE_LOG(LogTemp, Error, TEXT("POOL: No enemy was added to pool"));
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("POOL: %d enemies were added to pool"), EnemyPool.Num());
	}
}