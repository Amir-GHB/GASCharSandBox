// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
//#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "SPCharPlayerState.generated.h"
/**
 * 
 */

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class GASCHARSANDBOX_API ASPCharPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	ASPCharPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
    UAttributeSet* GetAttributeSet() const { return AttributeSet; };

	


	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	
};
