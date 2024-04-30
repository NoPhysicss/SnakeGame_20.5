// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedFood.h"

// Sets default values
ASpeedFood::ASpeedFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpeedFood::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpeedFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

