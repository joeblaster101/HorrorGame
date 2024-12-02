// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "HorrorGameCharacter.h"
#include "CC_Drone.h"
#include "CC_GameInstance.generated.h"

UCLASS()
class HORRORGAME_API UCC_GameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ACC_Drone* DroneRef;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	AHorrorGameCharacter* PlayerRef;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	AHorrorGamePlayerController* HorrorGameController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Power;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float BatteryCharge;

};
