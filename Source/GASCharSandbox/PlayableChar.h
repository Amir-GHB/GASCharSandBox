// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
//#include "Player/SPCharPlayerState.h"
#include "PlayableChar.generated.h"
//#include "SPCharPlayerState.generated.h"

/**
 * 
 */

UCLASS()
//class ASPCharPlayerState;
class GASCHARSANDBOX_API APlayableChar : public ABaseCharacter
{
	GENERATED_BODY()
	

private: 
	void LockMovementSettings();

	

protected:
	virtual void BeginPlay() override;
	
    
	


public:
	APlayableChar();

	

	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	bool OrientRotationToMovement = true;

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	UAbilitySystemComponent* GetAbilitySystemComponent() const
	{  return AbilitySystemComponent;  }
	
private:
	void InitAbilityActorInfo();
};
