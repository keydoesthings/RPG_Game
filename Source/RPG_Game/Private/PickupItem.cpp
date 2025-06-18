// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupItem.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "RPGCharacter.h" // Replace with your actual character class

APickupItem::APickupItem()
{
	PrimaryActorTick.bCanEverTick = true;

	// Collision
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	CollisionComponent->InitSphereRadius(50.f);
	CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionComponent->SetCollisionObjectType(ECC_WorldDynamic);
	CollisionComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	CollisionComponent->SetGenerateOverlapEvents(true);

	RootComponent = CollisionComponent;

	// Bind overlap event
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &APickupItem::OnOverlapBegin);

	// Mesh
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void APickupItem::BeginPlay()
{
	Super::BeginPlay();
}

void APickupItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(FRotator(0.f, 60.f * DeltaTime, 0.f));
}

void APickupItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
								 AActor* OtherActor,
								 UPrimitiveComponent* OtherComp,
								 int32 OtherBodyIndex,
								 bool bFromSweep,
								 const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		// Example: Check if it's your player
		ARPGCharacter* Player = Cast<ARPGCharacter>(OtherActor);
		if (Player)
		{
			UE_LOG(LogTemp, Log, TEXT("Item picked up!"));
			UInventoryComponent* PlayerInventory = Player->FindComponentByClass<UInventoryComponent>();
			PlayerInventory->AddItem(Item);
			Destroy();
		}
	}
}

void APickupItem::OnPickedUp()
{
	UE_LOG(LogTemp, Log, TEXT("Item picked up!"));
	
}