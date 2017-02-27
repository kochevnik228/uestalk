// Fill out your copyright notice in the Description page of Project Settings.

#include "STALKERPrototype.h"
#include "Characters/BaseHumanCharacter.h"
#include "WeaponInventoryObject.h"

UWeaponInventoryObject::UWeaponInventoryObject()
{

}

void UWeaponInventoryObject::UseItem(ABaseHumanCharacter * Character)
{
	Character->FirstWeapon = this;
}
