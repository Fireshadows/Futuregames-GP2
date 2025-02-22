// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/InventorySystem/Inventory.h"

// Sets default values
UInventory::UInventory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = false;

	//DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	//RootComponent = DummyRoot;
}

bool UInventory::AddItem(AActor* InventoryItem)
{
	for (int32 i = 0; i < Inventory.Num(); i++)
	{
		if (Inventory[i] == nullptr)
		{
			Inventory[i] = InventoryItem;
			return true;
		}
	}
	return false;
	//Inventory.Add(InventoryItem);
}

void UInventory::RemoveItem(int Index)
{
	Inventory[Index] = nullptr;
}

int UInventory::ItemCount()
{
	int count = 0;
	for (int32 i = 0; i < Inventory.Num(); i++)
	{
		if (Inventory[i] != nullptr)
		{
			count++;
		}
	}
	return count;
}

bool UInventory::IsNotFull()
{
	return ItemCount() < Inventory.Num();
}

// Called when the game starts or when spawned
void UInventory::BeginPlay()
{	
	Super::BeginPlay();
	Inventory.Init(nullptr, InventorySize);
}

void UInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickfunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickfunction);
}

