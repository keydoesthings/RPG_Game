// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "RPGCharacter.h"

void ARPGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = 
	ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputMapping, 0);
	}
}

void ARPGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARPGPlayerController::HandleMove);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ARPGPlayerController::HandleLook);
	}
}

void ARPGPlayerController::HandleMove(const FInputActionValue& Value)
{	
	if (ARPGCharacter* MyCharacter = Cast<ARPGCharacter>(GetPawn()))
	{
		MyCharacter->Move(Value.Get<FVector2D>());
	}
}

void ARPGPlayerController::HandleLook(const FInputActionValue& Value)
{
	if (ARPGCharacter* MyCharacter = Cast<ARPGCharacter>(GetPawn()))
	{
		MyCharacter->Look(Value.Get<FVector2D>());
	}
}