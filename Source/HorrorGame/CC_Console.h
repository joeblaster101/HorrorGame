// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/BoxComponent.h>
#include "CC_Console.generated.h"



UCLASS()
class HORRORGAME_API ACC_Console : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACC_Console();

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* RootCollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};