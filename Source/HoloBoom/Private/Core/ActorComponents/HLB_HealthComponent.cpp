// Xarblanca Studios 2025. All rights reserved.


#include "Core/ActorComponents/HLB_HealthComponent.h"

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

	Health = InitialHealth;
}


// Called every frame
void UHLB_HealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UHLB_HealthComponent::DoDamage(int32 Damage)
{
	UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__));

	Health -= Damage;

	if (Health <= 0)
	{
		// Die :(
	}
}

void UHLB_HealthComponent::DoHeal(int32 Heal)
{
	UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__));

	Health += Heal;

	if (Health > InitialHealth)
	{
		Health = InitialHealth;
	}
}

void UHLB_HealthComponent::RestoreInitialHealth()
{
	UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__));

	Health = InitialHealth;
}

