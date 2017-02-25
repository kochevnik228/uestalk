// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BaseInventoryObject.h"
#include "CharacterInventory.h"
#include "BaseInventoryActor.generated.h"

UCLASS()
class STALKERPROTOTYPE_API ABaseInventoryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseInventoryActor();

public: //Components

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	UStaticMeshComponent* ItemMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	TSubclassOf<UBaseInventoryObject> ItemObjectClass;

	UBaseInventoryObject* ItemObject;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool TakeInventoryActor(UCharacterInventory* TargetInventory);
	
};
