// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/SPCharPlayerState.h"
#include "AbilitySystem/SandBoxAbilitySystemComponent.h"
#include "AbilitySystem/SandBoxAttributeSet.h"


ASPCharPlayerState::ASPCharPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<USandBoxAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<USandBoxAttributeSet>("AttributeSet");
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	



	

}

UAbilitySystemComponent* ASPCharPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


