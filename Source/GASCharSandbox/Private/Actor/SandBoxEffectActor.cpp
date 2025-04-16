// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystemComponent.h"
#include "Actor/SandBoxEffectActor.h"
#include "AbilitySystem/SandBoxAttributeSet.h"
#include "AbilitySysteminterface.h"
#include "Components/SphereComponent.h"

// Sets default values
ASandBoxEffectActor::ASandBoxEffectActor()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject <USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());

}

void ASandBoxEffectActor::Onoverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Overlapping"));

	//Change to apply Game Effects
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))

	{
		const USandBoxAttributeSet* SandBoxAttributeSet = Cast<USandBoxAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(USandBoxAttributeSet::StaticClass()));
	
		USandBoxAttributeSet* MutableSandBoxAttributeSet = const_cast<USandBoxAttributeSet*>(SandBoxAttributeSet);
		MutableSandBoxAttributeSet->SetHealth(SandBoxAttributeSet->GetHealth() + 25.f);
		Destroy();
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("THis is Health BABY"));
	
	
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Death BABY"));
	}

}

void ASandBoxEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void ASandBoxEffectActor::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Sphere ha begin"));
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ASandBoxEffectActor::Onoverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ASandBoxEffectActor::EndOverlap);

}

void ASandBoxEffectActor::HealUp(AActor* InputActor)
{
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(InputActor))

	{
		const USandBoxAttributeSet* SandBoxAttributeSet = Cast<USandBoxAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(USandBoxAttributeSet::StaticClass()));

		USandBoxAttributeSet* MutableSandBoxAttributeSet = const_cast<USandBoxAttributeSet*>(SandBoxAttributeSet);
		MutableSandBoxAttributeSet->SetHealth(SandBoxAttributeSet->GetHealth() + 25.f);
		Destroy();
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("THis is Health BABY"));


	}
}





