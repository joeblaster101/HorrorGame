// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CC_Scare_base.h"
#include "Components/SphereComponent.h"
#include "CC_Scare_Flashbang.generated.h"

/**
 * 
 */
UCLASS()
class HORRORGAME_API ACC_Scare_Flashbang : public ACC_Scare_base
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintImplementableEvent)
	void DoFlashBange();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* ShpereComponent;

	ACC_Scare_Flashbang();

protected:
	virtual void BeginPlay() override;
	
};
