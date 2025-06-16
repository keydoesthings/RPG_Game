// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupItem.h"

// Sets default values
APickupItem::APickupItem()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

	Sphere->SetSphereRadius(100);
	Sphere->SetGenerateOverlapEvents(true);
	Sphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Sphere->SetCollisionObjectType(ECC_WorldDynamic); // or ECC_GameTraceChannel1 if custom
	Sphere->SetCollisionResponseToAllChannels(ECR_Ignore);
	Sphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &APickupItem::OnBeginOverlap);
}

void APickupItem::OnBeginOverlap(UPrimitiveComponent* OverlappedComp,
								 AActor* OtherActor,
								 UPrimitiveComponent* OtherComp,
								 int32 OtherBodyIndex,
								 bool bFromSweep,
								 const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Display, TEXT("PickupItem::OnBeginOverlap"));
	if (ARPGCharacter* Char = Cast<ARPGCharacter>(OtherActor))
	{
		UE_LOG(LogTemp, Display, TEXT("cast successful"));
		if (UInventoryComponent* Inventory = Char->FindComponentByClass<UInventoryComponent>())
		{
			UE_LOG(LogTemp, Display, TEXT("inventory component found"));
			if (Char->GetController() && Char->GetController()->IsPlayerController())
			{
			
			}
			Inventory->AddItem(ItemDataAsset);
			UE_LOG(LogTemp, Log, TEXT("Picked up item: %s by %s"), *ItemDataAsset->GetName(), *GetOwner()->GetName());
			Destroy();
		}
	}
}


