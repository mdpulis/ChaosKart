// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ChaosKartCharacter.generated.h"

UCLASS()
class CHAOSKART_API AChaosKartCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AChaosKartCharacter();

//Blueprint Editable Variables
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float KartMaxSpeed = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeToReachMaxSpeed = 3.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TurnSpeed = 60.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float kartCurrentSpeed = 0.0f;

private:


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



	UFUNCTION(BlueprintCallable)
	void Accelerate(float deltaTime);
	UFUNCTION(BlueprintCallable)
	void Decelerate(float deltaTime);

	UFUNCTION(BlueprintCallable)
	void MoveLeft(float deltaTime);
	UFUNCTION(BlueprintCallable)
	void MoveRight(float deltaTime);
};
