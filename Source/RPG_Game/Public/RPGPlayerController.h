// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "RPGPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class RPG_GAME_API ARPGPlayerController : public APlayerController
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
	// Input Mapping
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> InputMapping;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

	// Input Functions
	void HandleMove(const FInputActionValue& Value);
	void HandleLook(const FInputActionValue& Value);
};
	