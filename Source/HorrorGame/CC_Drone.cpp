// Fill out your copyright notice in the Description page of Project Settings.


#include "CC_Drone.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Components/BillboardComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Engine/LocalPlayer.h"
#include "CC_GameInstance.h"
#include "CC_Scare_Flashbang.h"

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

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComonent"));
	if (StaticMeshComponent)
		StaticMeshComponent->SetupAttachment(CapsuleComponent);

	FlashPoint = CreateDefaultSubobject<UBillboardComponent>(TEXT("flashpoint"));
	if (FlashPoint)
		FlashPoint->SetupAttachment(CapsuleComponent);

	BoxFlashbang = CreateDefaultSubobject<UBoxComponent>(TEXT("boxflashbag"));
	if (BoxFlashbang)
		BoxFlashbang->SetupAttachment(CapsuleComponent);

	flashbagMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("flashbagMesh"));
	if (flashbagMesh)
		flashbagMesh->SetupAttachment(CapsuleComponent);
	 
	Flashlight = CreateDefaultSubobject<USpotLightComponent>(TEXT("Flashlight"));
	if (Flashlight)
		Flashlight->SetupAttachment(CapsuleComponent);
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACC_Drone::BeginPlay()
{
	Super::BeginPlay();
	UCC_GameInstance* GameInstance = Cast<UCC_GameInstance>(GetGameInstance());
	GameInstance->DroneRef = this;



}

void ACC_Drone::DoScare(FHitResult hit)
{
	ACC_Scare_Flashbang* flash = Cast<ACC_Scare_Flashbang>(hit.GetActor());
	flash->DoFlashBange();
	flash->Destroy();
}

// Called every frame
void ACC_Drone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!Controller)
	{
		//UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' controller no there"), *GetNameSafe(this));
		
	}
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
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' you fuck it no inputs you labotimite"), *GetNameSafe(this));
	}
}

void ACC_Drone::Escape(const FInputActionValue& Value)
{
	UCC_GameInstance* GameInstance = Cast<UCC_GameInstance>(GetGameInstance());
	GameInstance->HorrorGameController->Possess(GameInstance->PlayerRef);;
}

void ACC_Drone::Escape2()
{
	UCC_GameInstance* GameInstance = Cast<UCC_GameInstance>(GetGameInstance());
	GameInstance->HorrorGameController->Possess(GameInstance->PlayerRef);
}

void ACC_Drone::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		//UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' move"), *GetNameSafe(this));
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
		//UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' look"), *GetNameSafe(this));
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

FHitResult ACC_Drone::InteractLineTrace()
{

	FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("Trace")), true, this);
	RV_TraceParams.bTraceComplex = true;
	RV_TraceParams.bReturnPhysicalMaterial = false;

	FHitResult Hit(ForceInit);
	FVector3d Start = this->GetActorLocation();
	FVector3d End = Start + this->GetActorForwardVector() * 100000.0f;

	GetWorld()->LineTraceSingleByChannel(
		Hit,		//resultd
		Start,	//start
		End, //end
		ECC_Pawn, //collision channel
		RV_TraceParams
	);

	DrawDebugLine(
		GetWorld(),
		Start,
		End,
		FColor::Red,
		true, // Persistent
		10000.0f, // Duration
		1.0f // Thickness
	);
	return Hit;
}

void ACC_Drone::Collect()
{
	FHitResult Hit = InteractLineTrace();
	UCC_GameInstance* GameInstance = Cast<UCC_GameInstance>(GetGameInstance());

	if (Hit.GetActor()->ActorHasTag("Battery"))
	{
		GameInstance->Power = GameInstance->Power + GameInstance->BatteryCharge;
	}



}


