// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "STALKERPrototype.h"
#include "STALKERPrototypeGameMode.h"
#include "STALKERPrototypeHUD.h"
#include "STALKERPrototypeCharacter.h"

ASTALKERPrototypeGameMode::ASTALKERPrototypeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player_Blueprints/BP_PlayerCharacter"));//FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ASTALKERPrototypeHUD::StaticClass();
}
