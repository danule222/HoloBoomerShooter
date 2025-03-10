// Xarblanca Studios 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "HLB_Enemy.generated.h"

UCLASS()
class HOLOBOOM_API AHLB_Enemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHLB_Enemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
