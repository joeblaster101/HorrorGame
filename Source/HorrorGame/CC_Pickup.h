// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include <string>
#include "CC_Pickup.generated.h"

UCLASS()
class HORRORGAME_API ACC_Pickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACC_Pickup();

	UPROPERTY(VisibleAnywhere)
	USphereComponent* ShpereComponent;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



};
