// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HealthComponent.h"
#include "InventoryComponent.h"
#include "RPGCharacter.generated.h"

UCLASS()
class RPG_GAME_API ARPGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARPGCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UHealthComponent* Health;

	UPROPERTY(VisibleAnywhere)
	UInventoryComponent* Inventory;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void Move(const FVector2D& Input);
	void Look(const FVector2D& Input);

	UFUNCTION()
	void OnCapsuleBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
							   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
							   bool bFromSweep, const FHitResult& SweepResult);
};
