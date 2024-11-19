// Fill out your copyright notice in the Description page of Project Settings.


#include "CC_Drone.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Engine/LocalPlayer.h"

// Sets default values
ACC_Drone::ACC_Drone()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACC_Drone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACC_Drone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACC_Drone::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// upes
		//EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		//EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Movey
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACC_Drone::Move);

		// Looky
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACC_Drone::Look);

		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACC_Drone::Look);
	}
	else
	{
		printf("shits fuck  input system!!!");
	}
}

