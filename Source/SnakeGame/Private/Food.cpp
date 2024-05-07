// Fill out your copyright notice in the Description page of Project Settings.


#include "Food.h"
#include "SnakeBase.h"

// Sets default values
AFood::AFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFood::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFood::Interact(AActor* Interactor, bool bIsHead)
{
	int X = (rand() % 2880) - 1440;
	int Y = (rand() % 2880) - 1440;

	X = X - (X % 120);
	Y = Y - (Y % 120);

	FVector NewLoc = FVector(X, Y, 0);

	auto Snake = Cast<ASnakeBase>(Interactor);
	if (IsValid(Snake))
	{
		Snake->AddSnakeElement();
		SetActorLocation(NewLoc);
	}
}

