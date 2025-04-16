// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayableChar.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h" // to resolve UCharacterMovementComponent
#include "Player/SPCharPlayerState.h"

void APlayableChar::BeginPlay()
{
	Super::BeginPlay();

	LockMovementSettings();

}


void APlayableChar::LockMovementSettings()
{

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	

}

void APlayableChar::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//initAbility actor info for server
	InitAbilityActorInfo();
	
}

void APlayableChar::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitAbilityActorInfo();
}


void APlayableChar::InitAbilityActorInfo()
{
	
	ASPCharPlayerState* SPCharPlayerState = GetPlayerState<ASPCharPlayerState>();
	check(SPCharPlayerState);
	if (!SPCharPlayerState)
	{
		
		UE_LOG(LogTemp, Error, TEXT("PlayerState is Null!!!"));
		return;
	}
	SPCharPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(SPCharPlayerState, this);
	AbilitySystemComponent = SPCharPlayerState->GetAbilitySystemComponent();
	AttributeSet = SPCharPlayerState->GetAttributeSet();



	//Debugging code shoud be REMOVED
	/*
	ASPCharPlayerState* SPCharPlayerState = GetPlayerState<ASPCharPlayerState>();
	if (!SPCharPlayerState)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("SPChar is null!!!"));
		return;
	}
	AbilitySystemComponent = SPCharPlayerState->GetAbilitySystemComponent();
	AttributeSet = SPCharPlayerState->GetAttributeSet();
	if (AbilitySystemComponent)
	{
		SPCharPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(SPCharPlayerState, this);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("ASC is null in PossessedBy"));

	}
	*/

}





