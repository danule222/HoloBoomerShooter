// Xarblanca Studios 2025. All rights reserved.

#include "Core/ActorComponents/HLB_HealthComponent.h"

#include "Characters/HLB_Character.h"

// Sets default values for this component's properties
UHLB_HealthComponent::UHLB_HealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UHLB_HealthComponent::BeginPlay()
{
	Super::BeginPlay();

	MaxHealth = Health;
}

// Called every frame
void UHLB_HealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UHLB_HealthComponent::DoDamage(int32 Damage)
{
	Health -= Damage;

	// DIE
	if (Health <= 0)
	{
		Cast<AHLB_Character>(GetOwner())->Die();
		RestoreInitialHealth();

		UE_LOG(LogTemp, Display, TEXT("HEALTHCOMP: %s dead"), *GetOwner()->GetFName().ToString());
	}
}

void UHLB_HealthComponent::DoHeal(int32 Heal)
{
	Health += Heal;

	if (Health > MaxHealth)
	{
		Health = MaxHealth;
	}
}

void UHLB_HealthComponent::RestoreInitialHealth()
{
	Health = MaxHealth;
}