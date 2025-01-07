// Copyright Epic Games, Inc. All Rights Reserved.

#include "HoloBoomGameMode.h"
#include "HoloBoomCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHoloBoomGameMode::AHoloBoomGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
