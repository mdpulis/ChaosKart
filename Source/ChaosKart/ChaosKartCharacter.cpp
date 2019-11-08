// Fill out your copyright notice in the Description page of Project Settings.


#include "ChaosKartCharacter.h"

// Sets default values
AChaosKartCharacter::AChaosKartCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChaosKartCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AChaosKartCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (accelerating)
		Accelerate(DeltaTime);
	else
		Decelerate(DeltaTime);

	if (holdingLeft)
		MoveLeft(DeltaTime);
	if (holdingRight)
		MoveRight(DeltaTime);
}

// Called to bind functionality to input
void AChaosKartCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Accelerates the car in the forward direction
void AChaosKartCharacter::Accelerate(float deltaTime)
{
	if (kartCurrentSpeed < KartMaxSpeed)
	{
		kartCurrentSpeed += deltaTime * (KartMaxSpeed / TimeToReachMaxSpeed);
	}
	else
	{
		kartCurrentSpeed = KartMaxSpeed;
	}
	
	//AddMove
	AddMovementInput(GetActorForwardVector() * (deltaTime * kartCurrentSpeed));

}

void AChaosKartCharacter::Decelerate(float deltaTime)
{
	if (kartCurrentSpeed > 0)
		kartCurrentSpeed -= deltaTime * (KartMaxSpeed / TimeToReachMaxSpeed);
	else
		kartCurrentSpeed = 0.0f;

	AddMovementInput(GetActorForwardVector() * (deltaTime * kartCurrentSpeed));
}

void AChaosKartCharacter::MoveLeft(float deltaTime)
{
	FRotator NewRotation = FRotator(0.0f, (-1.0f * TurnSpeed) * deltaTime, 0.0f);

	FQuat QuatRotation = FQuat(NewRotation);

	this->AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);
}

void AChaosKartCharacter::MoveRight(float deltaTime)
{
	FRotator NewRotation = FRotator(0.0f, TurnSpeed * deltaTime, 0.0f);

	FQuat QuatRotation = FQuat(NewRotation);

	this->AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);
}