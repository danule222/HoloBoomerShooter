// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"

#include "HLB_WeaponComponent.generated.h"

class UHLB_Weapon;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class HOLOBOOM_API UHLB_WeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHLB_WeaponComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void SetWeapon(UHLB_Weapon* Weapon);
};
