// Fill out your copyright notice in the Description page of Project Settings.

#include "STALKERPrototype.h"
#include "BaseHumanCharacter.h"


// Sets default values
ABaseHumanCharacter::ABaseHumanCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Inventory = CreateDefaultSubobject<UCharacterInventory>("Inventory");

}

// Called when the game starts or when spawned
void ABaseHumanCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseHumanCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseHumanCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseHumanCharacter::MoveForward(float val)
{
	this->AddMovementInput(this->GetActorForwardVector(), val);
}

void ABaseHumanCharacter::MoveRight(float val)
{
	this->AddMovementInput(this->GetActorRightVector(), val);
}

void ABaseHumanCharacter::SwitchWeapon(int index)
{
	
}

void ABaseHumanCharacter::StartFire()
{

}

void ABaseHumanCharacter::EndFire()
{

}

void ABaseHumanCharacter::PreUseItemAction()
{
	RayCastForward(600);
}
