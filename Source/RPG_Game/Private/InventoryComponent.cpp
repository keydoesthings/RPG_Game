// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

TArray<UItemDataAsset*> UInventoryComponent::GetItems()
{
	return Items;
}

UItemDataAsset* UInventoryComponent::GetItem(int32 Index)
{
	if (Items.IsValidIndex(Index))
	{
		return Items[Index];
	}
	return nullptr;
}

int32 UInventoryComponent::AddItem(UItemDataAsset* Item)
{
	int32 AddIndex = Items.Add(Item);
	OnInventoryUpdated.Broadcast();
	return AddIndex;
}

int32 UInventoryComponent::RemoveItem(int32 Index)
{
	if (Items.IsValidIndex(Index))
	{
		int32 RemoveIndex = Items.Remove(Items[Index]);
		OnInventoryUpdated.Broadcast();
		return RemoveIndex;
	}
	return 0;
}