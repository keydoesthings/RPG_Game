// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttackComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPG_GAME_API UAttackComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	FVector BoxOffset = FVector(0.f, 50.f, 0.f);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	FVector BoxHalfSize = FVector(50.f, 50.f, 50.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	bool bDebug = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	FColor DebugHitColor = FColor::Red;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	FColor DebugMissColor = FColor::Green;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float DebugDuration = 2.f;
	
	UFUNCTION(BlueprintCallable, Category = "Attack")
	bool Attack(FHitResult& OutHit);
};
