// Fill out your copyright notice in the Description page of Project Settings.


#include "DestroyWall.h"
#include "SnakeBase.h"

// Sets default values
ADestroyWall::ADestroyWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADestroyWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADestroyWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADestroyWall::Interact(AActor* Interactor, bool bIsHead)
{
	auto Snake = Cast<ASnakeBase>(Interactor);
	if (IsValid(Snake))
	{
		Snake->Destroy();
	}
}

