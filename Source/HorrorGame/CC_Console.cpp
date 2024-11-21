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
	
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComonent"));
	if (StaticMeshComponent)
		StaticMeshComponent->SetupAttachment(RootCollisionMesh);

}

// Called when the game starts or when spawned
void ACC_Console::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACC_Console::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
