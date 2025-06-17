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
	return Items.Add(Item);
}

int32 UInventoryComponent::RemoveItem(int32 Index)
{
	if (Items.IsValidIndex(Index))
	{
		return Items.Remove(Items[Index]);
	}
	return 0;
}