// Fill out your copyright notice in the Description page of Project Settings.

#include "AttackComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

bool UAttackComponent::Attack(FHitResult& OutHit)
{
	AActor* Owner = GetOwner();
	if (!Owner) return false;

	FVector Forward = Owner->GetActorForwardVector();
	FVector Start = Owner->GetActorLocation() + Owner->GetActorRotation().RotateVector(BoxOffset);
	FVector End = Start + (Forward * TraceLength); // Trace distance
	FQuat Rotation = Owner->GetActorQuat();

	FCollisionShape Box = FCollisionShape::MakeBox(BoxHalfSize);
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(Owner);

	bool bHit = GetWorld()->SweepSingleByChannel(
		OutHit,
		Start,
		End,
		Rotation,
		CollisionChannel, // Use a custom trace channel if needed
		Box,
		QueryParams
	);

	// Debug Draw
	if (bDebug)
	{
		FColor BoxColor = bHit ? DebugHitColor : DebugMissColor;
		DrawDebugBox(GetWorld(), Start, BoxHalfSize, Rotation, BoxColor, bDebugPersistent, DebugDuration);
		DrawDebugBox(GetWorld(), End, BoxHalfSize, Rotation, BoxColor, bDebugPersistent, DebugDuration);
		DrawDebugLine(GetWorld(), Start, End, BoxColor, bDebugPersistent, DebugDuration, 0, 2.0f);
	}

	if (bHit && OutHit.GetActor())
	{
		// Apply damage to the hit actor
		UGameplayStatics::ApplyDamage(
			OutHit.GetActor(),
			DamageAmount,
			GetOwner()->GetInstigatorController(),
			GetOwner(),
			UDamageType::StaticClass()
		);
	}
	
	return bHit;
}