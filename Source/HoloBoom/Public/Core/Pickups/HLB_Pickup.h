// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "HLB_Pickup.generated.h"

class AHLB_Player;
class UHLB_PickupComponent;

UCLASS()
class HOLOBOOM_API AHLB_Pickup : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHLB_Pickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Pick(AHLB_Player* Player);

private:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UHLB_PickupComponent* PickupComponent;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* StaticMeshComponent;
};
