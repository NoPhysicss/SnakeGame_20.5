// Fill out your copyright notice in the Description page of Project Settings.
//

#include "SpeedFood.h"
#include "SnakeBase.h"
#include "TimerManager.h"
#include <ctime> 

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


void ASpeedFood::Interact(AActor* Interactor, bool bIsHead)
{
	auto Snake = Cast<ASnakeBase>(Interactor);

	if (IsValid(Snake))
	{
		GetWorldTimerManager().SetTimer(SpeedTimer, this, &ASnakeBase::SetSpeed, 2.0f, false, -0.2f);
		GetWorldTimerManager().SetTimer(SpeedTimer, 2000, &ASnakeBase::SetSpeed, 2.0f);
		Destroy();
	}
}



