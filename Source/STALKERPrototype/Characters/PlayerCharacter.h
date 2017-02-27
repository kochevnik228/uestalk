// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Characters/BaseHumanCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class STALKERPROTOTYPE_API APlayerCharacter : public ABaseHumanCharacter
{
	GENERATED_BODY()
public:

	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	void PlayerUseAction();

	void GetWeapon();
	
};
