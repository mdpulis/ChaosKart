#include "KartPawnCPP.h"

#include "Camera/CameraComponent.h"

#include "Engine/Engine.h"

#define print(displayText) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, TEXT(displayText));
#define printf(text, fstring) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, FString::Printf(TEXT(text), fstring))


// Sets default values
AKartPawnCPP::AKartPawnCPP()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AKartPawnCPP::BeginPlay()
{
	Super::BeginPlay();
	
	//Bind components
	this->playerCamera = dynamic_cast<UCameraComponent*>(this->GetComponentByClass(UCameraComponent::StaticClass()));
	//this->sedanMesh = dynamic_cast<USkeletalMesh*>(this->GetComponentByClass(USkeletalMesh::StaticClass()));
}

// Called every frame
void AKartPawnCPP::Tick(float DeltaTime)
{
	//MoveKart(DeltaTime);
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
void AKartPawnCPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AKartPawnCPP::MoveKart(float deltaTime)
{
	if (!playerCamera)
	{
		print("no player camera");
		return;
	}

	FVector forwardVector = this->GetActorForwardVector();
	//print("X: %d, Y: %d, Z: %d", forwardVector.X, forwardVector.Y, forwardVector.Z);
	//if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("X: %d, Y: %d, Z: %d", forwardVector.X, forwardVector.Y, forwardVector.Z));
	//if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("X: %d, Y: %d, Z: %d", forwardVector.X, forwardVector.Y, forwardVector.Z));
	//printf("X: %d", forwardVector.X);
	//printf("Y: %d", forwardVector.Y);
	//printf("Z: %d", forwardVector.Z);
	printf("X: %6.4lf", forwardVector.X);
	printf("Y: %6.4lf", forwardVector.Y);
	printf("Z: %6.4lf", forwardVector.Z);

	FVector newLocation = FVector(this->GetActorLocation().X, this->GetActorLocation().Y + kartCurrentSpeed * deltaTime, this->GetActorLocation().Z);
	//this->SetActorLocation(newLocation, false);
	this->AddActorLocalOffset(forwardVector * kartCurrentSpeed * deltaTime, true);

	//AddMovementInput(this->GetActorForwardVector() * (deltaTime * KartSpeed));


	//print("moving");
}

// Accelerates the car in the forward direction
void AKartPawnCPP::Accelerate(float deltaTime)
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
	this->AddActorWorldOffset(GetActorForwardVector() * kartCurrentSpeed * deltaTime, true, 0, ETeleportType::None);

	//AddMovementInput(GetActorForwardVector() * (deltaTime * kartCurrentSpeed));

}

void AKartPawnCPP::Decelerate(float deltaTime)
{
	if (kartCurrentSpeed > 0)
		kartCurrentSpeed -= deltaTime * (KartMaxSpeed / TimeToReachMaxSpeed);
	else
		kartCurrentSpeed = 0.0f;

	this->AddActorWorldOffset(GetActorForwardVector() * kartCurrentSpeed * deltaTime, true, 0, ETeleportType::None);

	//AddMovementInput(GetActorForwardVector() * (deltaTime * kartCurrentSpeed));
}

void AKartPawnCPP::MoveLeft(float deltaTime)
{
	FRotator fRot = FRotator(0.0f, (-1.0f * TurnSpeed) * deltaTime, 0.0f);

	//FQuat QuatRotation = FQuat(FRotator(0.0f, -45.0f * deltaTime, 0.0f));
	FQuat QuatRotation = FQuat(fRot);

	this->AddActorLocalRotation(QuatRotation, true, 0, ETeleportType::None);
}

void AKartPawnCPP::MoveRight(float deltaTime)
{
	FRotator fRot = FRotator(0.0f, TurnSpeed * deltaTime, 0.0f);

	//FQuat QuatRotation = FQuat(FRotator(0.0f, 45.0f * deltaTime, 0.0f));
	FQuat QuatRotation = FQuat(fRot);

	this->AddActorLocalRotation(QuatRotation, true, 0, ETeleportType::None);
}

