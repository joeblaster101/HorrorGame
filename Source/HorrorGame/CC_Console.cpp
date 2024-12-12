// Fill out your copyright notice in the Description page of Project Settings.


#include "CC_Console.h"


// Sets default values
ACC_Console::ACC_Console()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootCollisionMesh = CreateDefaultSubobject<UBoxComponent>(FName("Collision Mesh"));
	if (RootCollisionMesh)
		SetRootComponent(RootCollisionMesh);
	
	Console = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Console"));
	if (Console)
		Console->SetupAttachment(RootCollisionMesh);

	Screen = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Screen"));
	if (Screen)
		Screen->SetupAttachment(RootCollisionMesh);

	lights = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("lights"));
	if (lights)
		lights->SetupAttachment(RootCollisionMesh);

}

// Called when the game starts or when spawned
void ACC_Console::BeginPlay()
{
	Super::BeginPlay();

	GameInstance = Cast<UCC_GameInstance>(GetGameInstance());
	GameInstance->Power = 80;
	GameInstance->BatteryCharge = 20;
}

// Called every frame
void ACC_Console::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
