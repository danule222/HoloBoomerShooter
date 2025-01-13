// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "Components/SphereComponent.h"
#include "CoreMinimal.h"

#include "HLB_PickupComponent.generated.h"

/**
 * Pickup component.
 */
UCLASS()
class HOLOBOOM_API UHLB_PickupComponent : public USphereComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
