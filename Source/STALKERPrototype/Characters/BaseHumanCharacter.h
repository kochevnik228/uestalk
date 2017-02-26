// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Inventory/CharacterInventory.h"
#include "BaseWeapon.h"
#include "Inventory/BaseInventoryObject.h"
#include "BaseHumanCharacter.generated.h"

UCLASS()
class STALKERPROTOTYPE_API ABaseHumanCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseHumanCharacter();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HumanCharacter)
	float MaxHP;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HumanCharacter)
	float HP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HumanCharacter)
	float Armor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HumanCharacter)
	float Stamina;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	UPROPERTY(BlueprintReadWrite, Category = Inventary)
		UCharacterInventory* Inventory;

	UPROPERTY(BlueprintReadWrite, Category = Inventary)
		ABaseWeapon* ActiveWeapon;

	UPROPERTY(BlueprintReadWrite, Category = Inventary)
		UBaseInventoryObject* FirstWeapon;

	UPROPERTY(BlueprintReadWrite, Category = Inventary)
		UBaseInventoryObject* SecondWeapon;


public: //Базовые функции

	UFUNCTION(BlueprintImplementableEvent, Category = Character)
	FHitResult RayCastForward(float Lenght);

	UFUNCTION(BlueprintImplementableEvent, Category = Character)
	FHitResult RayCastForwardFromLocation(FVector StartLocation, float Lenght);

	//Movement
	void MoveForward(float val);

	void MoveRight(float val);

	//Weapon
	void SwitchWeapon(int index);

	void StartFire();

	void EndFire();

	//Items
	void PreUseItemAction();

	
};
