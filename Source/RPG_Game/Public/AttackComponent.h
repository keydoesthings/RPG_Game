// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "AttackComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPG_GAME_API UAttackComponent : public USceneComponent
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Attack")
	void Attack();
};
