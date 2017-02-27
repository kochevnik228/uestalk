// Fill out your copyright notice in the Description page of Project Settings.


#include "STALKERPrototype.h"
#include "BaseInventoryObject.h"
#include "CharacterInventory.h"
#include "BaseInventoryActor.h"


// Sets default values
ABaseInventoryActor::ABaseInventoryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseInventoryActor::BeginPlay()
{
	Super::BeginPlay();
	this->Init();
}

void ABaseInventoryActor::Init()
{
	if (IsValid(this->ItemObjectClass))
	{
		//Поставить модельку и материал
		this->ItemObject = ::NewObject<UBaseInventoryObject>(this->GetWorld(), this->ItemObjectClass);
		this->GetItemMesh()->SetStaticMesh(this->ItemObject->ItemMesh);
		this->GetItemMesh()->SetMaterial(0, this->ItemObject->ItemMaterial);
	}
	else if (IsValid(this->ItemObject))
	{
		this->GetItemMesh()->SetStaticMesh(this->ItemObject->ItemMesh);
		this->GetItemMesh()->SetMaterial(0, this->ItemObject->ItemMaterial);
	}
	UE_LOG(LogTemp, Log, TEXT("Item created: "), *ItemObject->ItemName);
}

// Called every frame
void ABaseInventoryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ABaseInventoryActor::TakeInventoryActor(UCharacterInventory * TargetInventory)
{
	
	if (TargetInventory)
	{
		if (this->ItemObject)
		{
			//Доюавляем в инвентарь наш объект
			TargetInventory->AddItemToInventory(this->ItemObject);
			this->SetLifeSpan(0.1);
			return true;
		}
	}
	else
	{
		//::GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("IsValid(TargetInventory) && IsValid(this->ItemObject) == false"));
	}

	return false;
}


