// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGCharacter.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ARPGCharacter::ARPGCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	Health = CreateDefaultSubobject<UHealthComponent>(FName("Health"));
	Inventory = CreateDefaultSubobject<UInventoryComponent>(FName("Inventory"));
	Attack = CreateDefaultSubobject<UAttackComponent>(FName("Attack"));

	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetCapsuleComponent()->SetCollisionObjectType(ECC_Pawn);
	GetCapsuleComponent()->SetGenerateOverlapEvents(true);
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_GameTraceChannel1, ECR_Overlap);
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
