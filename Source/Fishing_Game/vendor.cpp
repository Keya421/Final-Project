// Fill out your copyright notice in the Description page of Project Settings.


#include "Vendor.h"

// Sets default values
AVendor::AVendor()
{
    // You can set default values for the inventory here
    FVendorItem Item1;
    Item1.ItemName = "Potion";
    Item1.ItemPrice = 10;
    Item1.ItemQuantity = 5;

    FVendorItem Item2;
    Item2.ItemName = "Sword";
    Item2.ItemPrice = 50;
    Item2.ItemQuantity = 2;

    Inventory.Add(Item1);
    Inventory.Add(Item2);
}

// Called when the game starts or when spawned
void AVendor::BeginPlay()
{
    Super::BeginPlay();
}

// Function to buy an item
bool AVendor::BuyItem(FString ItemName, int32& PlayerMoney, int32& PlayerInventoryCount)
{
    for (FVendorItem& Item : Inventory)
    {
        if (Item.ItemName == ItemName && Item.ItemQuantity > 0)
        {
            if (PlayerMoney >= Item.ItemPrice)
            {
                // Deduct money and increase player inventory count
                PlayerMoney -= Item.ItemPrice;
                PlayerInventoryCount++;

                // Reduce the item quantity in vendor's inventory
                Item.ItemQuantity--;
                return true; // Purchase successful
            }
            else
            {
                return false; // Not enough money
            }
        }
    }
    return false; // Item not found or out of stock
}
