// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupItem.generated.h"

// Forward declarations
class USphereComponent;
class UStaticMeshComponent;
class UItemDataAsset;

UCLASS()
class RPG_GAME_API APickupItem : public AActor
{
	GENERATED_BODY()
    
public:
	APickupItem();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
						AActor* OtherActor,
						UPrimitiveComponent* OtherComp,
						int32 OtherBodyIndex,
						bool bFromSweep,
						const FHitResult& SweepResult);

	// Components
	UPROPERTY(VisibleAnywhere)
	USphereComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComponent;

	// Item reference
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
	UItemDataAsset* Item;
	
	// Pickup behavior
	void OnPickedUp();
};