// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "Characters/HLB_Character.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "HLB_Enemy.generated.h"

class UHLB_HealthComponent;

UCLASS()
class HOLOBOOM_API AHLB_Enemy : public AHLB_Character
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHLB_Enemy();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Die();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitProperties() override;
};
