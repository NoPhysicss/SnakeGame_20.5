// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeBase.h"
#include "SnakeElementBase.h"
#include "Interactable.h"

// Sets default values
ASnakeBase::ASnakeBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ElementSize = 120.0;
	MovementSpeed = 0.5;
	CurrentMoveDirection = EMovementDirection::DOWN;

}

// Called when the game starts or when spawned
void ASnakeBase::BeginPlay()
{
	Super::BeginPlay();
	DesiredDirection = EMovementDirection::DOWN;
	SetActorTickInterval(MovementSpeed);
	AddSnakeElement(4);
}

// Called every frame
void ASnakeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
}

void ASnakeBase::AddSnakeElement(int ElementsNum)
{
	for (int i = 0; i < ElementsNum; ++i)
	{
		FVector NewLocation = FVector::ZeroVector;
		if (SnakeElements.Num() >= 3)
		{
			FVector LastElementLocation = SnakeElements.Last()->GetActorLocation();

			NewLocation = LastElementLocation;
		}
		else
		{
			NewLocation = FVector(SnakeElements.Num() * ElementSize, 0, 0);
		}

		FTransform NewTransform(NewLocation);
		ASnakeElementBase* NewSnakeElement = GetWorld()->SpawnActor<ASnakeElementBase>(SnakeElementClass, NewTransform);
		NewSnakeElement->SnakeOwner = this;
		int32 ElemIndex = SnakeElements.Add(NewSnakeElement);
		if (ElemIndex == 0)
		{
			NewSnakeElement->SetFirstElementType();
		}
	}
}

void ASnakeBase::Move()
{
	FVector MovementVector(ForceInitToZero);
	

	if (temp == PressedDirection)
	{
	}
	else
	{
		DesiredDirection = PressedDirection;
		if (CurrentMoveDirection != PressedDirection)
		{
			CurrentMoveDirection = DesiredDirection;
		}
	}
	 
	switch (CurrentMoveDirection)
	{
	case EMovementDirection::DOWN:
		temp = EMovementDirection::UP;
		break;
	case EMovementDirection::UP:
		temp = EMovementDirection::DOWN;
		break;
	case EMovementDirection::LEFT:
		temp = EMovementDirection::RIGHT;
		break;
	case EMovementDirection::RIGHT:
		temp = EMovementDirection::LEFT;
		break;
	}

	switch (DesiredDirection)
	{
		case EMovementDirection::UP:
				MovementVector.X += ElementSize;
				break;
		case EMovementDirection::DOWN:
				MovementVector.X -= ElementSize;
				break;
		case EMovementDirection::RIGHT:
				MovementVector.Y += ElementSize;
				break;
		case EMovementDirection::LEFT:
				MovementVector.Y -= ElementSize;
				break;
	}

	//AddActorWorldOffset(MovementVector);
	SnakeElements[0]->ToggleCollision();

	for (int i = SnakeElements.Num() - 1; i > 0; i--)
	{
		auto CurrentElement = SnakeElements[i];
		auto PrevElement = SnakeElements[i - 1];
		FVector PrevLocation = PrevElement->GetActorLocation();
		CurrentElement->SetActorLocation(PrevLocation);
	}

	SnakeElements[0]->AddActorWorldOffset(MovementVector); //SetActorLocation(GetActorLocation() + MovementVector); 
	SnakeElements[0]->ToggleCollision();
}

void ASnakeBase::SnakeElementOverlap(ASnakeElementBase* OverlappedElement, AActor* Other)
{
	if (IsValid(OverlappedElement))
	{
		int32 ElemIndex;
		SnakeElements.Find(OverlappedElement, ElemIndex);
		bool bIsFirst = ElemIndex == 0;
		IInteractable* InteractableInterface = Cast<IInteractable>(Other);
		if (InteractableInterface)
		{
			InteractableInterface->Interact(this, bIsFirst);
		}
	}
}

void ASnakeBase::SetSpeed(float BonusSpeed)
{
	SetActorTickInterval(BonusSpeed);

	FTimerHandle SpeedTimer;
	GetWorldTimerManager().SetTimer(SpeedTimer,
		FTimerDelegate::CreateWeakLambda(
			this,
			[this]
			{
				SetActorTickInterval(MovementSpeed);
			}),
		5.0f,
		false
	);
}
