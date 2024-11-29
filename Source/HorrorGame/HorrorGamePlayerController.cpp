// Copyright Epic Games, Inc. All Rights Reserved.

#include "HorrorGamePlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "CC_GameInstance.h"

void AHorrorGamePlayerController::BeginPlay()
{
	Super::BeginPlay();

	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
	UCC_GameInstance* GameInstance = Cast<UCC_GameInstance>(GetGameInstance());
	GameInstance->HorrorGameController = this;

}

void AHorrorGamePlayerController::PossessDrone()
{
	UCC_GameInstance* GameInstance = Cast<UCC_GameInstance>(GetGameInstance());
	this->UnPossess();
	this->Possess(GameInstance->DroneRef);
	//GetInputs();

}

void AHorrorGamePlayerController::PossessPlayer()
{
	UCC_GameInstance* GameInstance = Cast<UCC_GameInstance>(GetGameInstance());
	this->UnPossess();
	this->Possess(GameInstance->PlayerRef);
	//GetInputs();
}

void AHorrorGamePlayerController::GetInputs()
{
	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
}

