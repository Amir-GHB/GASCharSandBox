// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "SandBoxAttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class GASCHARSANDBOX_API USandBoxAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	USandBoxAttributeSet();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(USandBoxAttributeSet, Health)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(USandBoxAttributeSet, MaxHealth)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(USandBoxAttributeSet, Mana)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(USandBoxAttributeSet, MaxMana)
	
};
