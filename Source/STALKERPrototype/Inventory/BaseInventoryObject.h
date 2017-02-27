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

	//��� ��������
	UPROPERTY(BlueprintReadWrite, Category = "Items")
	EItemType ItemType;

	//�������� ��������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	FString ItemName;

	//����� ��������
	UPROPERTY(BlueprintReadWrite, Category = "Items")
	float Weight;

	//������ �������� � ���������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	UTexture2D* Image;

	//������ ��������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	UStaticMesh* ItemMesh;

	//�������� ��������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	UMaterial* ItemMaterial;

	//EItemType ItemType;

public:

	//��������� ������� �� �������
	UFUNCTION(BlueprintCallable, Category = "Items")
	class ABaseInventoryActor* DropItem();

	//�������� ������� � ���������
	UFUNCTION(BlueprintCallable, Category = "Items")
	int AddToInventory();

	//������������ ������� (2-���� � ���������)
	UFUNCTION(BlueprintCallable, Category = "Items")
	virtual void UseItem(class ABaseHumanCharacter * Character);

};
