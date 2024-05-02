// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "SpeedFood.generated.h"

UCLASS()
class SNAKEGAME_API ASpeedFood : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpeedFood();

	//bool bCanSpawn;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact(AActor* Interactor, bool bIsHead) override;

	/*void SetCanSpawn(bool bNewCanSpawn)
	{
		bCanSpawn = bNewCanSpawn;
	}

	// Call this function to check whether the food can spawn or relocate
	bool GetCanSpawn() const
	{
		return bCanSpawn;
	}*/
};