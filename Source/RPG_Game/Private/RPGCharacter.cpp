// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGCharacter.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ARPGCharacter::ARPGCharacter()
{
 	// Set this character to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;

	// Create components
	Health = CreateDefaultSubobject<UHealthComponent>(FName("Health"));
	Inventory = CreateDefaultSubobject<UInventoryComponent>(FName("Inventory"));
	Attack = CreateDefaultSubobject<UAttackComponent>(FName("Attack"));

	// Setup capsule collision for overlaps
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetCapsuleComponent()->SetCollisionObjectType(ECC_Pawn);
	GetCapsuleComponent()->SetGenerateOverlapEvents(true);
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Block);
	// Make sure capsule overlaps pickups which are typically WorldDynamic or custom channel
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_GameTraceChannel1, ECR_Overlap);
	// Optional: ignore other pawns to avoid blocking
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
}

// Called when the game starts or when spawned
void ARPGCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARPGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARPGCharacter::Move(const FVector2D& Input)
{
	if (Controller && Input.SizeSquared() > 0.0f)
	{
		const FRotator YawRotation(0, Controller->GetControlRotation().Yaw, 0);
		const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(Forward, Input.Y);
		AddMovementInput(Right, Input.X);
	}
}

void ARPGCharacter::Look(const FVector2D& Input)
{
	AddControllerYawInput(Input.X);
	AddControllerPitchInput(Input.Y * -1);
}
