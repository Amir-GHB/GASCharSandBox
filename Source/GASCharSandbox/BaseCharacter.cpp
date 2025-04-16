// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject <UStaticMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("OnHand"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	/*
	// Set the weapon mesh
	if (Weapon)
	{
		Weapon->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/Weapons/SM_Sword.SM_Sword'")));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Weapon is null"));
	}
	*/
}





