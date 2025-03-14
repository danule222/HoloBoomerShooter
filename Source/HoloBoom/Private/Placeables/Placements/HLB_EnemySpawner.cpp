// Xarblanca Studios 2025. All rights reserved.

#include "Placeables/Placements/HLB_EnemySpawner.h"

#include "Characters/Enemies/HLB_Enemy.h"
#include "Characters/Enemies/HLB_EnemyAIController.h"
#include "Components/CapsuleComponent.h"
#include "Core/GameModes/HLB_ZombieGameMode.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AHLB_EnemySpawner::AHLB_EnemySpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHLB_EnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	AGameModeBase* GameMode = UGameplayStatics::GetGameMode(GetWorld());
	if (AHLB_ZombieGameMode* ZombieGameMode = Cast<AHLB_ZombieGameMode>(GameMode))
	{
		ZombieGameMode->RegisterSpawner(this);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("SPAWNERS: Spawner was used without Zombie Game Mode being enabled"));
	}
}

// Called every frame
void AHLB_EnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHLB_EnemySpawner::Spawn(AHLB_Enemy* Enemy)
{
	Enemy->SetActorHiddenInGame(false);
	Enemy->SetActorEnableCollision(true);
	Enemy->GetCharacterMovement()->GravityScale = 1.f;
	Enemy->SetActorTickEnabled(true);
	Enemy->GetController()->SetActorTickEnabled(true);

	FVector ActorOrigin;
	FVector ActorBoxExtend;
	Enemy->GetActorBounds(true, ActorOrigin, ActorBoxExtend);

	Enemy->SetActorLocation(GetActorLocation() + FVector(0, 0, ActorBoxExtend.Z));

	FVector ActorSpawned = Enemy->GetActorLocation();
	UE_LOG(LogTemp, Display, TEXT("SPANWERS: Enemy spawned at %s"), *GetName());
}