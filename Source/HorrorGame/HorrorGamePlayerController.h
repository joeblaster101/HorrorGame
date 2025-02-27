// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HorrorGamePlayerController.generated.h"

class UInputMappingContext;

/**
 *
 */
UCLASS()
class HORRORGAME_API AHorrorGamePlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	virtual void BeginPlay() override;

public:

	///UFUNCTION(BlueprintCallable)
	//void PossessDrone();

	//UFUNCTION(BlueprintCallable)
	//void PossessPlayer();

	UFUNCTION()
	void GetInputs();


};
