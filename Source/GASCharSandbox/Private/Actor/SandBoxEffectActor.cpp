// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Actor/SandBoxEffectActor.h"
#include "AbilitySystem/SandBoxAttributeSet.h"
#include "AbilitySysteminterface.h"
#include "Components/SphereComponent.h"

// Sets default values
ASandBoxEffectActor::ASandBoxEffectActor()
{
 	
	PrimaryActorTick.bCanEverTick = false;
	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));

}





void ASandBoxEffectActor::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Sphere has begin"));


}

void ASandBoxEffectActor::ApplyEffect(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("ApplyEffect Been Called"));

	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);
	if (TargetASC == nullptr) return;
	
	check(GameplayEffectClass);

	FGameplayEffectContextHandle EffectContextHandl = TargetASC->MakeEffectContext();

	EffectContextHandl.AddSourceObject(this);

	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, ActorLevel, EffectContextHandl);
	FActiveGameplayEffectHandle ActiveEffectHandle = TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());

	const bool bIsInfinite = EffectSpecHandle.Data.Get()->Def.Get()->DurationPolicy == EGameplayEffectDurationType::Infinite;
	if (bIsInfinite && InfinitEffectRemovePolicy == EffectRemovePolicy::RemoveOnEndOverlap)
	{
		ActiveEffectHandles.Add(ActiveEffectHandle, TargetASC);
	}
}

void ASandBoxEffectActor::OnOverlap(AActor* TargetActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("ApplyEffect Been Overlapped"));
	if (InstantEffectApplyPolicy == EffectApplyPolicy::ApplyOnOverlap)
	{
		ApplyEffect(TargetActor, InstantGameplayEffect);

	}

	if (DurationEffectApplyPolicy == EffectApplyPolicy::ApplyOnOverlap)
	{
		ApplyEffect(TargetActor, DurationGameplayEffect);

	}
	if (InfinitEffectApplyPolicy == EffectApplyPolicy::ApplyOnOverlap)
	{
		ApplyEffect(TargetActor, InfinitGameplayEffect);
	}
}

void ASandBoxEffectActor::OnEndOverlap(AActor* TargetActor)
{
	if ((InstantEffectApplyPolicy == EffectApplyPolicy::ApplyOnEndOverlap))
	{
		ApplyEffect(TargetActor, InstantGameplayEffect);
	}

	if ((DurationEffectApplyPolicy == EffectApplyPolicy::ApplyOnEndOverlap))
	{
		ApplyEffect(TargetActor, DurationGameplayEffect);
	}

	if (InfinitEffectApplyPolicy == EffectApplyPolicy::ApplyOnEndOverlap)
	{
		ApplyEffect(TargetActor, InfinitGameplayEffect);
	}

	if (InfinitEffectRemovePolicy == EffectRemovePolicy::RemoveOnEndOverlap)
	{
		UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
		if (!IsValid(TargetASC)) return;

		TArray<FActiveGameplayEffectHandle> HandlesToRemove;
		for (TTuple<FActiveGameplayEffectHandle, UAbilitySystemComponent*> HandlePair : ActiveEffectHandles)
		{

			if (TargetASC == HandlePair.Value)
			{
				TargetASC->RemoveActiveGameplayEffect(HandlePair.Key, 1);
			}
			
		}
		for (auto& Handle : HandlesToRemove)
		{
			ActiveEffectHandles.FindAndRemoveChecked(Handle);
		}
	}
}






/*
void ASandBoxEffectActor::HealUp(AActor* InputActor)
{
	
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(InputActor))

	{

		const USandBoxAttributeSet* SandBoxAttributeSet = Cast<USandBoxAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(USandBoxAttributeSet::StaticClass()));
		float propHealth = SandBoxAttributeSet->GetHealth();
		FString HealthtoString = FString::SanitizeFloat(propHealth);
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("This is %s"), *HealthtoString));
		//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("This is %s"), SandBoxAttributeSet->GetHealth()));

		//USandBoxAttributeSet* MutableSandBoxAttributeSet = const_cast<USandBoxAttributeSet*>(SandBoxAttributeSet);
		//MutableSandBoxAttributeSet->SetHealth(SandBoxAttributeSet->GetHealth() + 25.f);
		//Destroy();

		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("THis is Health BABY"));


	}
	
}
*/





