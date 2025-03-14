// Xarblanca Studios 2025. All rights reserved.

#include "Weapon/HLB_WeaponComponent.h"

#include "Camera/CameraComponent.h"
#include "Characters/Player/HLB_Player.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Weapon/HLB_Weapon.h"

// Sets default values for this component's properties
UHLB_WeaponComponent::UHLB_WeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Weapon = nullptr;
}

// Called when the game starts
void UHLB_WeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	if (InitialWeapon)
	{
		UHLB_Weapon* WeaponObj = NewObject<UHLB_Weapon>(this, InitialWeapon);
		SetWeapon(WeaponObj);
	}

	AHLB_Player* Character = Cast<AHLB_Player>(GetOwner());

	if (Weapon)
	{
		// Attach the weapon to the First Person Character
		FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);

		// Weapon->Mesh->AttachToComponent(Character->GetMesh1P(), AttachmentRules, FName(TEXT("GripPoint")));

		// Set up action bindings
		if (APlayerController* PlayerController = Cast<APlayerController>(Character->GetController()))
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
					ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			{
				// Set the priority of the mapping to 1, so that it overrides the Jump action with the Fire action when using touch
				// input
				Subsystem->AddMappingContext(FireMappingContext, 1);
			}

			if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent))
			{
				// Fire
				EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &UHLB_WeaponComponent::Shoot);
			}
		}
	}
}

void UHLB_WeaponComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	AHLB_Player* Character = Cast<AHLB_Player>(GetOwner());

	// ensure we have a character owner
	if (Character != nullptr)
	{
		// remove the input mapping context from the Player Controller
		if (APlayerController* PlayerController = Cast<APlayerController>(Character->GetController()))
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
					ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			{
				Subsystem->RemoveMappingContext(FireMappingContext);
			}
		}
	}

	// maintain the EndPlay call chain
	Super::EndPlay(EndPlayReason);
}

// Called every frame
void UHLB_WeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHLB_WeaponComponent::SetWeapon(UHLB_Weapon* NewWeapon)
{
	UE_LOG(LogTemp, Display, TEXT("WEAPONS: %s weapon set"), *NewWeapon->Name.ToString());
	Weapon = NewWeapon;
}

void UHLB_WeaponComponent::Shoot()
{
	if (!Weapon)
		return;

	AHLB_Player* Player = Cast<AHLB_Player>(GetOwner());

	if (!Player)
		return;

	UCameraComponent* Camera = Player->GetFirstPersonCameraComponent();

	if (!Camera)
		return;

	Weapon->Shoot(Camera->GetComponentLocation(), Camera->GetForwardVector(), Player);
}