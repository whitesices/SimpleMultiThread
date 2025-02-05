// Copyright Epic Games, Inc. All Rights Reserved.

#include "Create54PluginGameMode.h"
#include "Create54PluginCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACreate54PluginGameMode::ACreate54PluginGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
