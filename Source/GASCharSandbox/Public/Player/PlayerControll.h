// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControll.generated.h"

/**
 * 
 */
class UInputMappingContext;
class UInputAction ;
struct FInputActionValue;
 
UCLASS()
class GASCHARSANDBOX_API APlayerControll : public APlayerController
{
	GENERATED_BODY()
public:

	APlayerControll();

protected:

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;
private:

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> SPCharContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;
	
	void Move(const FInputActionValue& InputActionValue);
};
