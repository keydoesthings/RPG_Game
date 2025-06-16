// Fill out your copyright notice in the Description page of Project Settings.

#include "AttackComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "CollisionQueryParams.h"

void UAttackComponent::Attack()
{
	AActor* Owner = GetOwner();
	if (!Owner) return;

	FVector StartLocation = Owner->GetActorLocation();
	FVector ForwardVector = Owner->GetActorForwardVector();

	float TraceDistance = 200.f;
	FVector EndLocation = StartLocation + ForwardVector * TraceDistance;
	FVector BoxHalfSize(50.f, 50.f, 50.f);
	FQuat BoxRotation = Owner->GetActorQuat();

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(Owner);

	FHitResult HitResult;

	bool bHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		BoxRotation,
		ECC_Visibility,
		FCollisionShape::MakeBox(BoxHalfSize),
		QueryParams
	);

	FColor TraceColor = bHit ? FColor::Red : FColor::Green;
	FVector TraceCenter = FMath::Lerp(StartLocation, EndLocation, 0.5f);

	DrawDebugBox(GetWorld(), TraceCenter, BoxHalfSize, BoxRotation, TraceColor, false, 2.0f);
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, TraceColor, false, 2.0f);

	if (bHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *HitResult.GetActor()->GetName());
	}
}