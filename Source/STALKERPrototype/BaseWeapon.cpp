// Fill out your copyright notice in the Description page of Project Settings.

#include "STALKERPrototype.h"
#include "Characters/BaseHumanCharacter.h"
#include "BaseWeapon.h"


// Sets default values
ABaseWeapon::ABaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ABaseWeapon::LoadAmmoToClip(FAmmoType ammotype, int32 Ammo)
{
	bool CanLoad = false;
	for (int8 i = 0; i < WeaponData.SupportedAmmoType.Num(); i++)
	{
		if (ammotype.Caliber == WeaponData.SupportedAmmoType[i].Caliber)
		{
			CanLoad = true;
			break;
		}
	}
	if (CanLoad)
	{
		LoadedAmmoType = ammotype;
		AmmoInClip = Ammo;
	}
	return false;
}

void ABaseWeapon::ShotOnce()
{
	if (AmmoInClip > 0)
	{
		AmmoInClip--;
		UE_LOG(LogTemp, Warning, TEXT("Fire once"));
		FHitResult Hit = WeaponOwner->RayCastForwardFromLocation(GetMuzzle()->GetComponentLocation(), 5000);
		UE_LOG(LogTemp, Warning, TEXT("Ammo:"), *FString::FromInt(AmmoInClip));

	}
}

void ABaseWeapon::InitWeapon(FWeaponData & Data)
{
	WeaponData = Data;
	if(GetWeaponMesh() && WeaponData.WeaponMesh && WeaponData.WeaponMaterial)
	{
		GetWeaponMesh()->SetSkeletalMesh(WeaponData.WeaponMesh);
		GetWeaponMesh()->SetMaterial(0, WeaponData.WeaponMaterial);
	}
}

