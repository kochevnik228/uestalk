// Fill out your copyright notice in the Description page of Project Settings.

#include "STALKERPrototype.h"
#include "BaseInventoryActor.h"


// Sets default values
ABaseInventoryActor::ABaseInventoryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	ItemMesh->SetupAttachment(RootComponent);
	//RootComponent = ItemMesh;
}

// Called when the game starts or when spawned
void ABaseInventoryActor::BeginPlay()
{
	Super::BeginPlay();
	if (IsValid(ItemObjectClass))
	{
		ItemObject = ::NewObject<UBaseInventoryObject>(GetWorld(), ItemObjectClass);
		//ItemMesh->
		ItemMesh->SetStaticMesh(ItemObject->ItemMesh);
		ItemMesh->SetMaterial(0, ItemObject->ItemMaterial);
	}
	else if(IsValid(ItemObject))
	{
		ItemMesh->SetStaticMesh(ItemObject->ItemMesh);
		ItemMesh->SetMaterial(0, ItemObject->ItemMaterial);
	}
	UE_LOG(LogTemp, Log, TEXT("Item created: "),*ItemObject->ItemName);
	
}

// Called every frame
void ABaseInventoryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ABaseInventoryActor::TakeInventoryActor(UCharacterInventory * TargetInventory)
{
	if(IsValid(TargetInventory) && IsValid(this->ItemObject))
	{
		TargetInventory->AddItemToInventory(this->ItemObject);
		ItemMesh->DestroyComponent();
		this->SetLifeSpan(0.5);
		return true;
	}

	return false;
}


