// Copyright Epic Games, Inc. All Rights Reserved.

#include "Wolf3DEnemyDisplayGameMode.h"
#include "Wolf3DEnemyDisplayCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWolf3DEnemyDisplayGameMode::AWolf3DEnemyDisplayGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
