// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedFood.h"
#include "SnakeBase.h"
#include <ctime>

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




void ASpeedFood::Interact(AActor* Interactor, bool bIsHead)
{

	
	

	auto Snake = Cast<ASnakeBase>(Interactor);

	if (IsValid(Snake))
	{
		Snake->SetSpeed(0.2f);

		SetActorLocation(FVector(0, 0, -200));
		

		FTimerHandle UnusedHandle;
		GetWorld()->GetTimerManager().SetTimer(UnusedHandle, 
			[this]
			{
				int X = (rand() % 3000) - 1620;
				int Y = (rand() % 3000) - 1620;

				X = X - (X % 120);
				Y = Y - (Y % 120);
				FVector NewLoc = FVector(X, Y, 0);

				SetActorLocation(NewLoc);
			}, 
			10.0f, false);
		
	}


}


