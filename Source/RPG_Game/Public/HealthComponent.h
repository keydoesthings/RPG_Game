// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthZeroDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthMaxDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthChangedDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPG_GAME_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadWrite, Category="Health", EditAnywhere)
	float DefaultHealth = 10.f;

	UPROPERTY(BlueprintReadWrite, Category="Health", EditAnywhere)
	float DefaultMaxHealth = 10.f;
	
	UPROPERTY(BlueprintReadOnly, Category="Health", VisibleAnywhere)
	float CurrentHealth;

	UPROPERTY(BlueprintReadOnly, Category="Health", VisibleAnywhere)
	float MaxHealth;

	UFUNCTION()
	void HandleTakeAnyDamage(
		AActor* DamagedActor,
		float Damage,
		const class UDamageType* DamageType,
		class AController* InstigatedBy,
		AActor* DamageCauser);
	
public:
	
	UFUNCTION(BlueprintCallable, Category="Health")
	float SetCurrentHealth(float Health);

	UFUNCTION(BlueprintCallable, Category="Health")
	float ChangeHealth(float Health);
	
	UFUNCTION(BlueprintCallable, Category="Health")
	float SetMaxHealth(float Health);

	UFUNCTION(BlueprintCallable, Category="Health")
	float ChangeMaxHealth(float Health);
	
	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnHealthZeroDelegate OnHealthZero;

	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnHealthMaxDelegate OnHealthMax;

	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnHealthChangedDelegate OnHealthChanged;
};