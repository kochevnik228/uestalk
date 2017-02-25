// Fill out your copyright notice in the Description page of Project Settings.

#include "STALKERPrototype.h"
#include "Inventory/BaseInventoryActor.h"
#include "PlayerCharacter.h"


void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent)
	
	PlayerInputComponent->BindAxis("MoveForward", this, &ABaseHumanCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABaseHumanCharacter::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &ACharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &ACharacter::AddControllerYawInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("UseEvent", IE_Pressed, this, &ABaseHumanCharacter::PreUseItemAction);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ABaseHumanCharacter::StartFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &ABaseHumanCharacter::EndFire);
}

void APlayerCharacter::PlayerUseAction()
{
	Cast<ABaseInventoryActor>(RayCastForward(300).Actor.Get())->TakeInventoryActor(Inventory);
}
