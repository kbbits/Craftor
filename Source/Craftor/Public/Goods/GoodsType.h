#pragma once

#include "Engine/DataTable.h"
#include "Engine/Texture2D.h"
#include "GoodsType.generated.h"

/*
* Represents a type of commoditiy that could be collected by the player.
* (or used as currency, crafting ingredients, etc.)
* Not all goods types will have specific actors if/when they are placed into the world.
*/
USTRUCT(BlueprintType)
struct FGoodsType : public FTableRowBase
{
	GENERATED_BODY()

public:
	// Internal name of this GoodsType. Must be unique.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
		FName Name;

	// Name displayed to player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
		FText DisplayName;

	// Thumbnail for GUI use
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
		TSoftObjectPtr<UTexture2D> Thumbnail;

	// Can this goods type be "used" by the player?
	// If = true, then a matching UsableGoodsType entry must exist.
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
	//	bool bUsable = false;

	// If this value is present it will be used during auto-value calculation instead of calculating it.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
		float OverrideValue;

	// Optional actor class to spawn when dropping goods into the world.
	// If not valid, it will be dropped as a generic GoodsPickup
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
		TSoftClassPtr<AActor> DropActorClass;

	// Optional class to use for placement as a structure in the game world.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
		TSoftClassPtr<AActor> PlaceableClass;

	// The default mesh to use when placing or dropping these goods into the world.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
		TSoftObjectPtr<UStaticMesh> DefaultMesh;

	// Override the material on the DefaultMesh with this mesh. 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Block)
		TSoftObjectPtr<class UMaterialInterface> OverrideMaterial;

	// Various tags related to this GoodsType.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
		TArray<FName> GoodsTags;

	FORCEINLINE bool operator==(const FGoodsType& OtherType) const
	{
		if (Name != OtherType.Name) return false;
		return true;
	}

	FORCEINLINE bool operator==(const FGoodsType& OtherType)
	{
		if (Name != OtherType.Name) return false;
		return true;
	}

	FORCEINLINE bool operator==(FGoodsType& OtherType)
	{
		if (Name != OtherType.Name) return false;
		return true;
	}

	FORCEINLINE bool operator==(const FName& OtherName) const
	{
		if (Name != OtherName) return false;
		return true;
	}

	FORCEINLINE bool operator==(const FName& OtherName)
	{
		if (Name != OtherName) return false;
		return true;
	}

	FORCEINLINE bool operator==(FName& OtherName)
	{
		if (Name != OtherName) return false;
		return true;
	}
};