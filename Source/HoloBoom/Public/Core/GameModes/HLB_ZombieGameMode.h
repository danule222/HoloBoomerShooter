// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "HLB_ZombieGameMode.generated.h"

class AHLB_Enemy;
class AHLB_EnemySpawner;

/**
 * Zombie game mode logic.
 */
UCLASS()
class HOLOBOOM_API AHLB_ZombieGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void RegisterSpawner(AHLB_EnemySpawner* Spawner);

	void EnemyKilled(AHLB_Enemy* Enemy);

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	/**
	 * ROUNDS
	 */

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Rounds, meta = (AllowPrivateAccess = "true"))
	int32 ActualRound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rounds, meta = (AllowPrivateAccess = "true"))
	int32 InitialEnemies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rounds, meta = (AllowPrivateAccess = "true"))
	int32 NewEnemiesPerRound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rounds, meta = (AllowPrivateAccess = "true", Units = "Seconds"))
	int32 TimeBetweenRounds;

	int32 EnemiesSpawnedThisRound;
	int32 KilledEnemies;
	FTimerHandle NewRoundTimerHandle;

	// Function that only should be called at the start of the game
	void SetRounds();
	// Logic to start new round
	void NewRound();
	// Function called by a timer to start a new round
	void StartNewRound();

	/**
	 * SPAWNERS
	 */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawners, meta = (AllowPrivateAccess = "true", Units = "Seconds"))
	int32 TimeBetweenSpawns;

	TArray<AHLB_EnemySpawner*> Spawners;
	FTimerHandle SpawnerTimerHandle;

	UFUNCTION()
	void SpawnEnemy();

	void SetSpawners();

	/**
	 * POOL
	 */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pool, meta = (AllowPrivateAccess = "true"))
	int32 MaxNumOfEnemies;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pool, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> EnemyClass;

	TArray<AHLB_Enemy*> EnemyPool;

	void SetPool();
};
