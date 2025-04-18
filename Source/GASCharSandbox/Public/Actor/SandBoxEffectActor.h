// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystem/SandBoxAttributeSet.h"
#include "GameplayEffectTypes.h"
#include "SandBoxEffectActor.generated.h"

UENUM(BlueprintType)
enum class EffectApplyPolicy : uint8
{
	ApplyOnOverlap UMETA(DisplayName = "ApplyOnOverlap"),
	ApplyOnEndOverlap UMETA(DisplayName = "ApplyOnEndOverlap"),
	DONotApply UMETA(DisplayName = "DONotApply")
};

UENUM(BlueprintType)
enum class EffectRemovePolicy : uint8
{
	RemoveOnEndOverlap UMETA(DisplayName = "RemoveOnEndOverlap"),
	DONotRemove UMETA(DisplayName = "DONotRemove")
};



class UGameplayEffects;



UCLASS()
class GASCHARSANDBOX_API ASandBoxEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	

	ASandBoxEffectActor();

	

	//	UFUNCTION(BlueprintCallable)
	//	virtual void HealUp(AActor* InputActor);

protected:
	
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	virtual void ApplyEffect(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bDestroyOnEffectRemoval = false;

	UFUNCTION(BlueprintCallable)
	virtual void OnOverlap(AActor* TargetActor);

	UFUNCTION(BlueprintCallable)
	virtual void OnEndOverlap(AActor* TargetActor);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> InstantGameplayEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EffectApplyPolicy InstantEffectApplyPolicy = EffectApplyPolicy::DONotApply;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> DurationGameplayEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EffectApplyPolicy DurationEffectApplyPolicy = EffectApplyPolicy::DONotApply;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> InfinitGameplayEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EffectApplyPolicy InfinitEffectApplyPolicy = EffectApplyPolicy::DONotApply;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EffectRemovePolicy InfinitEffectRemovePolicy = EffectRemovePolicy::RemoveOnEndOverlap;
	

	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActiveEffectHandles;

	//virtual void PreAttributeChange(const FGameplayAttribute& Attribue, float& NewValue) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ActorLevel = 1.f;

	

public:	
	

};
