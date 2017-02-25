// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "BaseInventoryObject.h"
#include "CharacterInventory.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STALKERPROTOTYPE_API UCharacterInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCharacterInventory();

	UFUNCTION(BlueprintCallable, Category = Inventary)
	int32 AddItemToInventory(UBaseInventoryObject* Item);

	UFUNCTION(BlueprintCallable, Category = Inventary)
	void RemoveItemFromInventory(UBaseInventoryObject* Item);

	UFUNCTION(BlueprintCallable, Category = Inventary)
	UBaseInventoryObject* GetItemByIndex(int i);

	UFUNCTION(BlueprintCallable, Category = Inventary)
	bool CanAddItemToInventary(UBaseInventoryObject* Item);

protected:

	bool bIsOverloaded = false;

	int ItemsAmount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	float MaxWeihgt;

	float TotalWeihgt;

	TArray<UBaseInventoryObject*> AllItems;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
