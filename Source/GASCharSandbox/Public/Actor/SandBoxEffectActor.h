// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystem/SandBoxAttributeSet.h"
#include "SandBoxEffectActor.generated.h"




class USphereComponent;

UCLASS()
class GASCHARSANDBOX_API ASandBoxEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	

	ASandBoxEffectActor();

	UFUNCTION()
	virtual void Onoverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		virtual void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

		UFUNCTION(BlueprintCallable)
		virtual void HealUp(AActor* InputActor);

protected:
	
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnyWhere)
	TObjectPtr<USphereComponent> Sphere;

	UPROPERTY(VisibleAnyWhere)
	TObjectPtr<UStaticMeshComponent> Mesh;

public:	
	

};
