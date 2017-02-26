// Fill out your copyright notice in the Description page of Project Settings.


#include "STALKERPrototype.h"
#include "BaseInventoryActor.h"


// Sets default values
ABaseInventoryActor::ABaseInventoryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//GetItemMesh() = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	//ItemMesh->SetupAttachment(RootComponent);
	//RootComponent = ItemMesh;
}

// Called when the game starts or when spawned
void ABaseInventoryActor::BeginPlay()
{
	Super::BeginPlay();
	if (IsValid(this->ItemObjectClass))
	{
		this->ItemObject = ::NewObject<UBaseInventoryObject>(this->GetWorld(), this->ItemObjectClass);
		//ItemMesh->
		this->GetItemMesh()->SetStaticMesh(this->ItemObject->ItemMesh);
		this->GetItemMesh()->SetMaterial(0, this->ItemObject->ItemMaterial);
	}
	else if(IsValid(this->ItemObject))
	{
		this->GetItemMesh()->SetStaticMesh(this->ItemObject->ItemMesh);
		this->GetItemMesh()->SetMaterial(0, this->ItemObject->ItemMaterial);
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
	
	if (TargetInventory)
	{
		::GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("IsValid(TargetInventory) == true"));
		if (this->ItemObject)
		{
			TargetInventory->AddItemToInventory(this->ItemObject);
			GetItemMesh()->DestroyComponent();
			this->SetLifeSpan(0.5);
			::GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("IsValid(this->ItemObject) == true"));
			return true;

		}
	}
	else
	{
		::GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("IsValid(TargetInventory) && IsValid(this->ItemObject) == false"));
	}

	return false;
}


