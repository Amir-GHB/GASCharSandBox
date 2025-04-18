// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SPCharDataConfig.generated.h"

/**
 * 
 */

    USTRUCT(BlueprintType)
    struct FSPCharVisuals
    {
		GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSoftObjectPtr<USkeletalMesh> CharSkeletalMesh;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSoftObjectPtr<UAnimInstance> AnimBlueprint;

	};
	USTRUCT(BlueprintType)
		struct FWeaponConfig 
	{
		GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName WeaponSocketName;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSoftObjectPtr<AActor> WeaponClass;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSoftObjectPtr<UStaticMesh> WeaponStaticMesh;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSoftObjectPtr<UTexture2D> WeaponIcon;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector WeaponEffectSPawnVector;


	};

	

	USTRUCT(BlueprintType)
		struct FAbilityConfig
	{
		GENERATED_BODY()

	};

	USTRUCT(BlueprintType)
		struct FSpCharAttributes
	{
		GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Health;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxHealth;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Mana;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxMana;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SpecialResource;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Armor;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Resistance;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CritChance;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CooldownReduction;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MovementSpeed;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Luck;

	};

	USTRUCT(BlueprintType)
	struct FAbilities
{
		GENERATED_BODY()



};

	USTRUCT(BlueprintType)
		struct FAnim
	{
		GENERATED_BODY()

	};

	

	//=======================================================================

	USTRUCT(BlueprintType)
	struct FSPCharFullConfig : public  FTableRowBase
	{
		GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ChracterName;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSPCharVisuals Visuals;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FWeaponConfig Weapon1;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FWeaponConfig Weapon2;


		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FWeaponConfig Weapon3;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSpCharAttributes Attributes;

		

		
	};











class GASCHARSANDBOX_API SPCharDataConfig
{
public:
	SPCharDataConfig();
	~SPCharDataConfig();
};
