#include "HealthComponent.h"

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	if (DefaultHealth > DefaultMaxHealth)
	{
		UE_LOG(LogTemp, Warning, TEXT("Default Health is greater than Default Max Health"));
	}
	SetMaxHealth(DefaultMaxHealth);
	SetCurrentHealth(DefaultHealth);

	if (AActor* Owner = GetOwner())
	{
		Owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::HandleTakeAnyDamage);
	}
}

void UHealthComponent::HandleTakeAnyDamage(
	AActor* DamagedActor,
	float Damage,
	const class UDamageType* DamageType,
	class AController* InstigatedBy,
	AActor* DamageCauser)
{
	ChangeHealth(-Damage);
}


float UHealthComponent::SetCurrentHealth(float Health)
{
	float prevHealth = CurrentHealth;
	CurrentHealth = FMath::Clamp(Health, 0.f, MaxHealth);

	if (CurrentHealth != prevHealth)
	{
		OnHealthChanged.Broadcast();
	}
	
	if (CurrentHealth <= 0.f)
	{
		OnHealthZero.Broadcast();
	}
	else if (CurrentHealth >= MaxHealth)
	{
		OnHealthMax.Broadcast();
	}

	return CurrentHealth;
}

float UHealthComponent::ChangeHealth(float Health)
{
	SetCurrentHealth(CurrentHealth + Health);
	return CurrentHealth;
}

float UHealthComponent::SetMaxHealth(float Health)
{
	MaxHealth = FMath::Max(0.f, Health);
	if (CurrentHealth > MaxHealth)
	{
		SetMaxHealth(MaxHealth);
	}

	return MaxHealth;
}

float UHealthComponent::ChangeMaxHealth(float Health)
{
	SetMaxHealth(MaxHealth + Health);
	return MaxHealth;
}
