// Xarblanca Studios 2025. All rights reserved.

#include "Core/Pickups/HLB_Pickup.h"

#include "Core/Pickups/HLB_PickupComponent.h"

// Sets default values
AHLB_Pickup::AHLB_Pickup()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PickupComponent = CreateDefaultSubobject<UHLB_PickupComponent>("PickupComponent");
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");

	if (StaticMeshComponent)
	{
		StaticMeshComponent->SetCollisionProfileName(TEXT("NoCollision"));

		if (PickupComponent)
		{
			StaticMeshComponent->AttachToComponent(PickupComponent, FAttachmentTransformRules::KeepRelativeTransform);
		}
	}
}

// Called when the game starts or when spawned
void AHLB_Pickup::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHLB_Pickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHLB_Pickup::Pick(AHLB_Player* Player)
{
	UE_LOG(LogTemp, Error, TEXT("Pick function not implemented."));
}