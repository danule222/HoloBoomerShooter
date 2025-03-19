// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"

#include "HLB_WeaponComponent.generated.h"

class UHLB_Weapon;
class UInputAction;
class UInputMappingContext;

enum class ETriggerEvent : uint8;

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

	// Called when the game ends
	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetWeapon(UHLB_Weapon* Weapon);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<UHLB_Weapon> InitialWeapon;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* FireMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UInputAction* ShootAction;

	UPROPERTY()
	UHLB_Weapon* Weapon;

	void Shoot(ETriggerEvent TriggerEvent);
};
