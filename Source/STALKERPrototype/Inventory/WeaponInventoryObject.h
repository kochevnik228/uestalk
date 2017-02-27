// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Inventory/BaseInventoryObject.h"
#include "WeaponInventoryObject.generated.h"

USTRUCT(Blueprintable)
struct FAmmoType
{
	GENERATED_USTRUCT_BODY()
public:
	FAmmoType() { Damage = 1.f; }
	FAmmoType(int inCal, float inDamage) : Caliber(inCal), Damage(inDamage) {}

	UPROPERTY(EditAnywhere, Category = AmmoType)
	int Caliber;

	UPROPERTY(EditAnywhere, Category = AmmoType)
	float Damage;
};

UENUM(Blueprintable)
enum class EFireMode : uint8
{
	SingleMode,
	BurstsMode
};


USTRUCT(Blueprintable)
struct FWeaponData
{
	GENERATED_USTRUCT_BODY()
public:
	//Базовые параметры пушки

	//Название пушки
	UPROPERTY(EditAnywhere, Category = WeaponData)
	FString WeaponName;

	//Модель пушки
	UPROPERTY(EditAnywhere, Category = WeaponData)
	USkeletalMesh* WeaponMesh;

	//Материал пушки
	UPROPERTY(EditAnywhere, Category = WeaponData)
	UMaterial* WeaponMaterial;

	//Звук выстрела
	UPROPERTY(EditAnywhere, Category = WeaponData)
	USoundWave* FireSound;

	//Тип стрельбы
	UPROPERTY(EditAnywhere, Category = WeaponData)
	EFireMode FireMode = EFireMode::SingleMode;

	//Можно ли менять режим стрельбы
	UPROPERTY(EditAnywhere, Category = WeaponData)
	bool bCanSelectFireMode = false;

	//Максимальное количесво патронов в обойме
	UPROPERTY(EditAnywhere, Category = WeaponData)
	int8 MaxAmmoInClip = 30;

	//Поддерживаемые типы патронов
	UPROPERTY(EditAnywhere, Category = WeaponData)
	TArray<FAmmoType> SupportedAmmoType;

	//Время охлаждения после выстрела
	UPROPERTY(EditAnywhere, Category = WeaponData)
	float ShotCoolDown = 0.05;

	//ВРемя перезарядки
	UPROPERTY(EditAnywhere, Category = WeaponData)
	float ReloadTime = 1;
};





/**
 * 
 */
UCLASS(Blueprintable)
class STALKERPROTOTYPE_API UWeaponInventoryObject : public UBaseInventoryObject
{
	GENERATED_BODY()
public:

	UWeaponInventoryObject();

	UFUNCTION(BlueprintCallable, Category = Weapon)
	void UseItem(ABaseHumanCharacter * Character) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	FWeaponData WeaponData;
	
	
};
