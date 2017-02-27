// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "BaseInventoryObject.generated.h"


UENUM(Blueprintable)
enum class EItemType : uint8
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

	//Тип предмета
	UPROPERTY(BlueprintReadWrite, Category = "Items")
	EItemType ItemType;

	//Название предмета
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	FString ItemName;

	//Масса предмета
	UPROPERTY(BlueprintReadWrite, Category = "Items")
	float Weight;

	//Иконка предмета в инвентаре
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	UTexture2D* Image;

	//Модель предмета
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	UStaticMesh* ItemMesh;

	//Материал предмета
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	UMaterial* ItemMaterial;

	//EItemType ItemType;

public:

	//Выбросить предмет на уровень
	UFUNCTION(BlueprintCallable, Category = "Items")
	class ABaseInventoryActor* DropItem();

	//Добавить предмет в инвентарь
	UFUNCTION(BlueprintCallable, Category = "Items")
	int AddToInventory();

	//Использовать предмет (2-клик в инвентаре)
	UFUNCTION(BlueprintCallable, Category = "Items")
	virtual void UseItem(class ABaseHumanCharacter * Character);

};
