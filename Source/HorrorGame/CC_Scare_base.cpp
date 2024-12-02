// Fill out your copyright notice in the Description page of Project Settings.


#include "CC_Scare_base.h"

// Sets default values
ACC_Scare_base::ACC_Scare_base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACC_Scare_base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACC_Scare_base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

