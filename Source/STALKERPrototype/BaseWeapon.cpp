// Fill out your copyright notice in the Description page of Project Settings.

#include "STALKERPrototype.h"
#include "Characters/BaseHumanCharacter.h"
#include "Kismet/KismetSystemLibrary.h"
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

bool ABaseWeapon::LoadAmmoToClip(FAmmoType ammotype, int8 Ammo)
{
	bool CanLoad = false;
	for (int8 i = 0; i < SupportedAmmoType.Num(); i++)
	{
		if (ammotype.Caliber == SupportedAmmoType[i].Caliber)
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
		//FVector location;
		FHitResult Hit = WeaponOwner->RayCastForwardFromLocation(Muzzle->GetComponentLocation(), 5000);
		UE_LOG(LogTemp, Warning, TEXT("Ammo:"), *FString::FromInt(AmmoInClip));
		/*TArray<AActor*> IgnireActors;
		if (UKismetSystemLibrary::LineTraceSingle(GetWorld(), Muzzle->GetComponentLocation(), location, ETraceTypeQuery::TraceTypeQuery1, false, IgnireActors, EDrawDebugTrace::Type::ForDuration, Hit, true))
		{
			if (Cast<ACharacter>(Hit.GetActor()))
				UE_LOG(LogTemp, Warning, TEXT("Hit to Character"));
		}
		if (FireMode == BurstsMode)
		{
			GetWorldTimerManager().SetTimer(CoolDownTimer, this, &ABaseWeapon::ShotOnce, ShotCoolDown, false);
		}*/

	}
}

