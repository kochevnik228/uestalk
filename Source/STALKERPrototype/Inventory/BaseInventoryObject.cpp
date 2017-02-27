// Fill out your copyright notice in the Description page of Project Settings.

#include "STALKERPrototype.h"
#include "BaseInventoryActor.h"
#include "Characters/BaseHumanCharacter.h"
#include "BaseInventoryObject.h"

UBaseInventoryObject::UBaseInventoryObject()
{

}

ABaseInventoryActor * UBaseInventoryObject::DropItem()
{
	class UWorld* World = GetWorld();
	class ACharacter* Character = UGameplayStatics::GetPlayerCharacter(World, 0);
	ABaseInventoryActor* sac = World->SpawnActor<ABaseInventoryActor>(ABaseInventoryActor::StaticClass(), Character->GetActorLocation(), Character->GetActorRotation());
	sac->ItemObject = this;
	sac->ItemObjectClass = this->StaticClass();
	sac->Init();
	return sac;
}

int UBaseInventoryObject::AddToInventory()
{
	return 0;
}

void UBaseInventoryObject::UseItem(ABaseHumanCharacter * Character)
{

}
