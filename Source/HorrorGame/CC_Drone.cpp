// Fill out your copyright notice in the Description page of Project Settings.


#include "CC_Drone.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Engine/LocalPlayer.h"
#include "CC_GameInstance.h"

// Sets default values
ACC_Drone::ACC_Drone()
{
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("DroneCapsuleComponent"));
	if (CapsuleComponent)
		SetRootComponent(CapsuleComponent);

	CapsuleComponent->InitCapsuleSize(55.f, 96.0f);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("DroneCameraComponent"));
	if (CameraComponent)
		CameraComponent->SetupAttachment(CapsuleComponent);

;

	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACC_Drone::BeginPlay()
{
	Super::BeginPlay();
	UCC_GameInstance* GameInstance = Cast<UCC_GameInstance>(GetGameInstance());
	GameInstance->DroneRef = this;

}

// Called every frame
void ACC_Drone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACC_Drone::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// upes
		//EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		//EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACC_Drone::Move);

		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACC_Drone::Look);

		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACC_Drone::Look);

		EnhancedInputComponent->BindAction(EscapeAction, ETriggerEvent::Triggered, this, &ACC_Drone::Escape);

	}
	else
	{
		printf("shits fuck  input system!!!");
	}
}

void ACC_Drone::Escape(const FInputActionValue& Value)
{

}

void ACC_Drone::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void ACC_Drone::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}
