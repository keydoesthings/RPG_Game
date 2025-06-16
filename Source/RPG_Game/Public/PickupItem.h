// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/MeshComponent.h"
#include "RPGCharacter.h"
#include "ItemDataAsset.h"
#include "PickupItem.generated.h"


UCLASS()
class RPG_GAME_API APickupItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupItem();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PickupItem")
	UItemDataAsset* ItemDataAsset;
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;	
	
	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;

	UPROPERTY(VisibleAnywhere)
	UMeshComponent* Mesh;

	UPROPERTY()
	ARPGCharacter* OverlappingCharacter;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp,
						AActor* OtherActor,
						UPrimitiveComponent* OtherComp,
						int32 OtherBodyIndex,
						bool bFromSweep,
						const FHitResult& SweepResult);

};
