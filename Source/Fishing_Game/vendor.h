// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Vendor.generated.h"

// Struct to define items the vendor sells
USTRUCT(BlueprintType)
struct FVendorItem
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    FString ItemName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    int32 ItemPrice;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    int32 ItemQuantity;
};

UCLASS()
class YOURGAME_API AVendor : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AVendor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Vendor's inventory
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vendor")
    TArray<FVendorItem> Inventory;

    // Function to buy an item
    UFUNCTION(BlueprintCallable, Category = "Vendor")
    bool BuyItem(FString ItemName, int32& PlayerMoney, int32& PlayerInventoryCount);
};
