// Xarblanca Studios 2025. All rights reserved.

#include "Weapon/HLB_WeaponComponent.h"

#include "Camera/CameraComponent.h"
#include "Characters/Player/HLB_Player.h"
#include "Core/GameFramework/HLB_Globals.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "UI/HUD/HLB_ZombieHUD.h"
#include "Weapon/HLB_Gun.h"
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
		UHLB_Weapon* WeaponObj = NewObject<UHLB_Weapon>(GetOwner(), InitialWeapon);
		SetWeapon(WeaponObj);
	}

	// TEST

	AHLB_Player* Playerop = Cast<AHLB_Player>(GetOwner());
	if (Playerop)
	{
		if (GetOwner()->ActorHasTag(TAG_PLAYER) && Playerop->IsLocallyControlled())
		{
			UE_LOG(LogTemp, Warning, TEXT("Buena ahi %d"), Playerop->Tags.Num());

			AController* owo = Playerop->GetController();
			if (APlayerController* jeje = Cast<APlayerController>(owo))
			{
				UE_LOG(LogTemp, Warning, TEXT("jiji %d"), jeje->GetHUD());
				if (AHLB_ZombieHUD* jud = Cast<AHLB_ZombieHUD>(jeje->GetHUD()))
				{
					jud->SetAmmo(22);
					jud->SetMagazines(22);
				}
			}
		}
	}

	// TEST

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
				EnhancedInputComponent->BindAction(
					ShootAction, ETriggerEvent::Started, this, &UHLB_WeaponComponent::Shoot, ETriggerEvent::Started);
				EnhancedInputComponent->BindAction(
					ShootAction, ETriggerEvent::Triggered, this, &UHLB_WeaponComponent::Shoot, ETriggerEvent::Triggered);
				EnhancedInputComponent->BindAction(
					ShootAction, ETriggerEvent::Completed, this, &UHLB_WeaponComponent::Shoot, ETriggerEvent::Completed);

				// Reload
				EnhancedInputComponent->BindAction(ReloadAction, ETriggerEvent::Triggered, this, &UHLB_WeaponComponent::Reload);
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
	// TODO: Implement enemy's weapons
	if (GetOwner()->ActorHasTag(TAG_ENEMY))
		return;

	if (!NewWeapon)
	{
		UE_LOG(LogTemp, Error, TEXT("WEAPONS: SetWeapon was invoked with null parameter."));
		return;
	}

	Weapon = NewWeapon;

	// Get HUD
	UWorld* World = GetWorld();
	if (!World)
		return;
	UPlayer* Player = GetOwner()->GetNetOwningPlayer();
	if (!Player)
		return;
	AHUD* HUD = Player->GetPlayerController(World)->GetHUD();
	AHLB_ZombieHUD* ZHUD = Cast<AHLB_ZombieHUD>(HUD);
	if (!ZHUD)
		return;

	if (!GetOwner()->HasAuthority())
		UE_LOG(LogTemp, Warning, TEXT("%d"), ZHUD);

	Weapon->Initialize(ZHUD);

	UE_LOG(LogTemp, Display, TEXT("WEAPONS: %s weapon set"), *NewWeapon->Name.ToString());
}

void UHLB_WeaponComponent::Shoot(ETriggerEvent TriggerEvent)
{
	if (!Weapon)
		return;
	AHLB_Player* Player = Cast<AHLB_Player>(GetOwner());
	if (!Player)
		return;
	UCameraComponent* Camera = Player->GetFirstPersonCameraComponent();
	if (!Camera)
		return;

	Weapon->Shoot(Camera->GetComponentLocation(), Camera->GetForwardVector(), Player, TriggerEvent);
}

void UHLB_WeaponComponent::Reload()
{
	if (!Weapon)
		return;
	UHLB_Gun* Gun = Cast<UHLB_Gun>(Weapon);
	if (!Gun)
		return;

	Gun->Reload();
}