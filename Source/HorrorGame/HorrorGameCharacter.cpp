// Copyright Epic Games, Inc. All Rights Reserved.

#include "HorrorGameCharacter.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Engine/LocalPlayer.h"
#include "CC_GameInstance.h"
#include "HorrorGamePlayerController.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AHorrorGameCharacter

AHorrorGameCharacter::AHorrorGameCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;	
}

void AHorrorGameCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
	UCC_GameInstance* GameInstance = Cast<UCC_GameInstance>(GetGameInstance());
	GameInstance->PlayerRef = this;

}

void AHorrorGameCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (!Controller)
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' you fuck it you labotimite"), *GetNameSafe(this));
	}
}

//////////////////////////////////////////////////////////////////////////// Input

void AHorrorGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// upes
		//EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		//EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Movey
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AHorrorGameCharacter::Move);

		// Looky
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AHorrorGameCharacter::Look);

		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AHorrorGameCharacter::Look);

		EnhancedInputComponent->BindAction(Interact, ETriggerEvent::Triggered, this, &AHorrorGameCharacter::Interacte);


	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' you fuck it no inputs you labotimite"), *GetNameSafe(this));
	}
}

void AHorrorGameCharacter::WhatInFront()
{
	UE_LOG(LogTemplateCharacter, Error, TEXT("Femboys"), *GetNameSafe(this));
	FHitResult Hit = Interacte();
	bool bDidHit = Hit.bBlockingHit;

	if (bDidHit)
	{
		if (Hit.GetActor()->ActorHasTag("console"))
		{
			AHorrorGamePlayerController* pcPlayerControllerRef = Cast<AHorrorGamePlayerController>(Controller);
			pcPlayerControllerRef->PossessPlayer();
		}
	}
}
FHitResult AHorrorGameCharacter::Interacte()
{

	UE_LOG(LogTemplateCharacter, Error, TEXT("twinks"), *GetNameSafe(this));
	FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("Trace")), true, this);
	RV_TraceParams.bTraceComplex = true;
	RV_TraceParams.bReturnPhysicalMaterial = false;

	FHitResult Hit(ForceInit);
	FVector3d Start = GetFirstPersonCameraComponent()->GetComponentLocation();
	FVector3d End = Start + GetFirstPersonCameraComponent()->GetComponentLocation() * 100.0f;
	
	GetWorld()->LineTraceSingleByChannel(
		Hit,		//resultd
		Start,	//start
		End, //end
		ECC_Pawn, //collision channel
		RV_TraceParams
	);

	DrawDebugLine(
		GetWorld() ,
		Start,
		End,
		FColor::Red,
		true, // Persistent
		10000.0f, // Duration
		1.0f // Thickness
	);
	return Hit;
}

void AHorrorGameCharacter::Move(const FInputActionValue& Value)
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

void AHorrorGameCharacter::Look(const FInputActionValue& Value)
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

void AHorrorGameCharacter::Interacte(const FInputActionValue& Value)
{
	WhatInFront();
}

