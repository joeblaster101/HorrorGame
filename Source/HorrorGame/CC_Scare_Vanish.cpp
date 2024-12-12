// Fill out your copyright notice in the Description page of Project Settings.


#include "CC_Scare_Vanish.h"

ACC_Scare_Vanish::ACC_Scare_Vanish()
{
	ShpereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("ShpereComponent"));
	if (ShpereComponent)
		SetRootComponent(ShpereComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComonent"));
	if (StaticMeshComponent)
		StaticMeshComponent->SetupAttachment(ShpereComponent);




}