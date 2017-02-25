// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

USTRUCT()
struct FAmmoType
{
	GENERATED_USTRUCT_BODY()
public:
	FAmmoType() {}
	FAmmoType(int inCal, float inDamage) : Caliber(inCal), Damage(inDamage) {}
	int Caliber;
	float Damage;
	float Mass;
	FString AmmoName;
};

UENUM()
enum EFireMode
{
	SingleMode,
	BurstsMode
};

UCLASS()
class STALKERPROTOTYPE_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

	class ABaseHumanCharacter* WeaponOwner;
//------------Base Weapon parameters
	FString WeaponName;

	EFireMode FireMode;

	bool bCanSelectFireMode;

//-------------Ammo Parameters
	int8 MaxAmmoInClip;

	TArray<FAmmoType> SupportedAmmoType;

	float ShotCoolDown;

public: //Base components

	UPROPERTY(BlueprintReadWrite, Category = "Weapon")
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(BlueprintReadWrite, Category = "Weapon")
	USceneComponent* Muzzle;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	UParticleSystem* ShotParticleEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	USoundWave* ShotSound;

public:

	int AmmoInClip;

	FAmmoType LoadedAmmoType;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	bool LoadAmmoToClip(FAmmoType ammotype, int8 Ammo);

	void ShotOnce();

	FTimerHandle CoolDownTimer;
	
	
};
