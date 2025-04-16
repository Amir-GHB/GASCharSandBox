// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BaseCharacter.generated.h"

//class UAbilitySystemComponent;
//class UAttributeSet;

UCLASS(Abstract)
class GASCHARSANDBOX_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	
	ABaseCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttribute() const { return AttributeSet; };
	
	

protected:
	
	virtual void BeginPlay() override;

protected:
	
	UPROPERTY(EditAnyWhere, Category = "Combat")
	TObjectPtr<UStaticMeshComponent> Weapon;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	



};
