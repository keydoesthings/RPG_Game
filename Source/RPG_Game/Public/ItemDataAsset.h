// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemDataAsset.generated.h"

UCLASS(BlueprintType, Blueprintable)
class RPG_GAME_API UItemDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FString Name;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	float HealthEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	float EnergyEffect;
	
	UItemDataAsset()
		: Name(TEXT("Default Item"))
		, HealthEffect(0.f)
		, EnergyEffect(0.f)
	{}
};