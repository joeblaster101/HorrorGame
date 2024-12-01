// Fill out your copyright notice in the Description page of Project Settings.


#include "CC_Pickup.h"
#include "Components/SphereComponent.h"

// Sets default values
ACC_Pickup::ACC_Pickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ShpereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("ShpereComponent"));
	if (ShpereComponent)
		SetRootComponent(ShpereComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComonent"));
	if (StaticMeshComponent)
		StaticMeshComponent->SetupAttachment(ShpereComponent);

}

// Called when the game starts or when spawned
void ACC_Pickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACC_Pickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACC_Pickup::WhenPickedUp()
{
	Destroy();
}

