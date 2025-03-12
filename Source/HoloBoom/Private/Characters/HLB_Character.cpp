// Xarblanca Studios 2025. All rights reserved.

#include "Characters/HLB_Character.h"

#include "Core/ActorComponents/HLB_HealthComponent.h"
#include "Weapon/HLB_WeaponComponent.h"

// Sets default values
AHLB_Character::AHLB_Character()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Weapon component
	WeaponComponent = CreateDefaultSubobject<UHLB_WeaponComponent>(TEXT("WeaponComponent"));

	// Health component
	HealthComponent = CreateDefaultSubobject<UHLB_HealthComponent>(TEXT("HealthComponent"));
}

// Called when the game starts or when spawned
void AHLB_Character::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHLB_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AHLB_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}