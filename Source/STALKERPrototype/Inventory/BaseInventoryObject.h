// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "BaseInventoryObject.generated.h"

UENUM()
enum EItemType
{
	Weapon,
	Ammo,
	Medicamentes,
	Eat,
	Other
};

/**
 * 
 */
UCLASS(Blueprintable)
class STALKERPROTOTYPE_API UBaseInventoryObject : public UObject
{
	GENERATED_BODY()
	
public:

	UBaseInventoryObject();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	FString ItemName;

	UPROPERTY(BlueprintReadWrite, Category = "Items")
	float Weight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	UTexture2D* Image;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	UStaticMesh* ItemMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	UMaterial* ItemMaterial;

	//EItemType ItemType;

public:

	UFUNCTION()
	AActor* DropItem();

	UFUNCTION()
	int AddToInventory();

	virtual void UseItem();

};
