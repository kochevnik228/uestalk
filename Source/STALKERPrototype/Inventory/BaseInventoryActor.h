// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BaseInventoryActor.generated.h"

class UBaseInventoryObject;
class UCharacterInventory;

UCLASS()
class STALKERPROTOTYPE_API ABaseInventoryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseInventoryActor();

public: //Components

	UFUNCTION(BlueprintImplementableEvent, Category = Inventory)
	UStaticMeshComponent* GetItemMesh();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	TSubclassOf<UBaseInventoryObject> ItemObjectClass;

	UBaseInventoryObject* ItemObject;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = Inventory)
	bool TakeInventoryActor(UCharacterInventory* TargetInventory);

	UFUNCTION(BlueprintCallable, Category = Inventory)
	void Init();
	
};
