// Fill out your copyright notice in the Description page of Project Settings.

#include "STALKERPrototype.h"
#include "CharacterInventory.h"


// Sets default values for this component's properties
UCharacterInventory::UCharacterInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


int32 UCharacterInventory::AddItemToInventory(UBaseInventoryObject * Item)
{
	::GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("UCharacterInventory::AddItemToInventory(UBaseInventoryObject * Item)"));
	TotalWeihgt += Item->Weight;
	ItemsAmount++;

	if(TotalWeihgt > MaxWeihgt)
		bIsOverloaded = true;

	return AllItems.Add(Item);
}

void UCharacterInventory::RemoveItemFromInventory(UBaseInventoryObject* Item)
{
	TotalWeihgt -= Item->Weight;
	ItemsAmount--;

	if(TotalWeihgt < MaxWeihgt)
		bIsOverloaded = false;

	AllItems.Remove(Item);
}

UBaseInventoryObject* UCharacterInventory::GetItemByIndex(int i)
{
	if(AllItems[i])
	return AllItems[i];
	return nullptr;
}

bool UCharacterInventory::CanAddItemToInventary(UBaseInventoryObject * Item)
{
	return (TotalWeihgt + Item->Weight <= MaxWeihgt);
}

// Called when the game starts
void UCharacterInventory::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCharacterInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

