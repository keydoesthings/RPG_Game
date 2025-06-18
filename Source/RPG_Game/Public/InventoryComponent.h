// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemDataAsset.h"
#include "InventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPG_GAME_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TArray<TObjectPtr<UItemDataAsset>> Items;

public:
	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnInventoryUpdated OnInventoryUpdated;
	
	UFUNCTION()
	TArray<UItemDataAsset*> GetItems();

	UFUNCTION()
	UItemDataAsset* GetItem(int Index);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	int32 AddItem(UItemDataAsset* Item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	int32 RemoveItem(int Index);
};
