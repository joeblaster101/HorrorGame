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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ACC_Drone* DroneRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AHorrorGameCharacter* PlayerRef;
};
