// Xarblanca Studios 2025. All rights reserved.

#include "Weapon/HLB_WeaponComponent.h"

// Sets default values for this component's properties
UHLB_WeaponComponent::UHLB_WeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UHLB_WeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

// Called every frame
void UHLB_WeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}