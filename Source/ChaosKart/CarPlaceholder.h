// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CarPlaceholder.generated.h"

UCLASS()
class CHAOSKART_API ACarPlaceholder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACarPlaceholder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
