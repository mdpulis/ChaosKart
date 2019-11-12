// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "KartPawnCPP.generated.h"

UCLASS()
class CHAOSKART_API AKartPawnCPP : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AKartPawnCPP();


	//Blueprint Editable Variables
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float KartMaxSpeed = 1000.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeToReachMaxSpeed = 1.5f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TurnSpeed = 60.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float kartCurrentSpeed = 0.0f;

private:

//Components
private:
	class UCameraComponent* playerCamera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool accelerating = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool holdingLeft = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool holdingRight = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveKart(float deltaTime);

	UFUNCTION(BlueprintCallable)
	void Accelerate(float deltaTime);
	UFUNCTION(BlueprintCallable)
	void Decelerate(float deltaTime);

	UFUNCTION(BlueprintCallable)
	void MoveLeft(float deltaTime);
	UFUNCTION(BlueprintCallable)
	void MoveRight(float deltaTime);
};
