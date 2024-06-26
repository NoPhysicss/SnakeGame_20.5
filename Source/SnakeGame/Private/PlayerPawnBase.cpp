// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawnBase.h"
#include "Camera/CameraComponent.h"
#include "SnakeBase.h"
#include "Components/InputComponent.h"

// Sets default values
APlayerPawnBase::APlayerPawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PawnCamera"));
	RootComponent = PawnCamera;

}

// Called when the game starts or when spawned
void APlayerPawnBase::BeginPlay()
{
	Super::BeginPlay();
	SetActorRotation(FRotator(-90, 0, 0));
	CreateSnakeActor();
}

// Called every frame
void APlayerPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Vertical", this, &APlayerPawnBase::HandlPlayerVerticalInput);
	PlayerInputComponent->BindAxis("Horizontal", this, &APlayerPawnBase::HandlPlayerHorizontallInput);
}

void APlayerPawnBase::CreateSnakeActor()
{
	SnakeActor = GetWorld()->SpawnActor<ASnakeBase>(SnakeActorClass, FTransform());
}

void APlayerPawnBase::HandlPlayerVerticalInput(float value)
{
	if (IsValid(SnakeActor))
	{
		if (value > 0 && SnakeActor->CurrentMoveDirection != EMovementDirection::UP)
		{
			SnakeActor->PressedDirection = EMovementDirection::UP;
		}
		else if (value < 0 && SnakeActor->CurrentMoveDirection != EMovementDirection::DOWN)
		{
			SnakeActor->PressedDirection = EMovementDirection::DOWN;
			
		}
	}
}

void APlayerPawnBase::HandlPlayerHorizontallInput(float value)
{
	if (IsValid(SnakeActor))
	{
		if (value > 0 && SnakeActor->CurrentMoveDirection != EMovementDirection::LEFT)
		{
			SnakeActor->PressedDirection = EMovementDirection::LEFT;
		}
		else if (value < 0 && SnakeActor->CurrentMoveDirection != EMovementDirection::RIGHT)
		{
			SnakeActor->PressedDirection = EMovementDirection::RIGHT;
		}
	}
}


