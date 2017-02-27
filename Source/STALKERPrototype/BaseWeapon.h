// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Inventory/WeaponInventoryObject.h"
#include "BaseWeapon.generated.h"



UCLASS()
class STALKERPROTOTYPE_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

	class ABaseHumanCharacter* WeaponOwner;


public: //Base components

	FWeaponData WeaponData;

	UFUNCTION(BlueprintImplementableEvent, Category = Weapon)
	USkeletalMeshComponent* GetWeaponMesh();

	UFUNCTION(BlueprintImplementableEvent, Category = Weapon)
	USceneComponent* GetMuzzle();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	UParticleSystem* ShotParticleEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	USoundWave* ShotSound;

public:

	int32 AmmoInClip;

	FAmmoType LoadedAmmoType;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	UFUNCTION(BlueprintCallable, Category = Weapon)
	bool LoadAmmoToClip(FAmmoType ammotype, int32 Ammo);

	UFUNCTION(BlueprintCallable, Category = Weapon)
	void ShotOnce();

	UFUNCTION(BlueprintCallable, Category = Weapon)
	void InitWeapon(FWeaponData & Data);
	

	FTimerHandle CoolDownTimer;
	
	
};
