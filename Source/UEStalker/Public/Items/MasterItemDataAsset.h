#pragma once

#include "CoreMinimal.h"
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Items/MasterItemStructs.h"
#include "MasterItemDataAsset.generated.h"

/**
 * Тут дизайнер заполняет данные предмета (конфиги).
 * Runtime значения (CurrDurability/CurrCharge/Stack) живут в ItemObject.
 */
UCLASS(BlueprintType)
class UMasterItemDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Details")
	FMasterItemDetails ItemDetails;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Trade")
	FItemTradeConfig TradeConfig;

	// Показываем только если предмет может иметь прочность (Оружие, Броня, Шлем и т.д.)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Durability", 
		meta=(EditCondition="ItemDetails.ItemCategory == EItemCategory::ItemCat_Weapons || ItemDetails.ItemCategory == EItemCategory::ItemCat_Armor || ItemDetails.ItemCategory == EItemCategory::ItemCat_Helmet", EditConditionHides))
	FItemDurabilityConfig DurabilityConfig;

	// Показываем, например, только для UsableItems (ПДА, Детекторы)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Charge",
		meta=(EditCondition="ItemDetails.ItemCategory == EItemCategory::ItemCat_UsableItems", EditConditionHides))
	FItemChargeConfig ChargeConfig;

	// Показываем для Брони, Шлемов, Рюкзаков
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Stats|Outfit",
		meta=(EditCondition="ItemDetails.ItemCategory == EItemCategory::ItemCat_Armor || ItemDetails.ItemCategory == EItemCategory::ItemCat_Helmet || ItemDetails.ItemCategory == EItemCategory::ItemCat_Backpack", EditConditionHides))
	FItemOutfitStatsConfig OutfitStatsConfig;

	// Показываем ТОЛЬКО если категория Weapons
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Stats|Weapon",
		meta=(EditCondition="ItemDetails.ItemCategory == EItemCategory::ItemCat_Weapons", EditConditionHides))
	FItemWeaponsStatsConfig WeaponStatsConfig;

	// Показываем только для Магазинов
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Stats|Magazine",
		meta=(EditCondition="ItemDetails.ItemSubCategory == EItemSubCategory::ItemSubCat_Attachments_Magazine", EditConditionHides))
	FItemMagazineConfig MagazineConfig;

	// Показываем для Еды, Воды, Медицины
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Stats|Consumable",
		meta=(EditCondition="ItemDetails.ItemSubCategory == EItemSubCategory::ItemSubCat_Items_Water || ItemDetails.ItemSubCategory == EItemSubCategory::ItemSubCat_Items_Food || ItemDetails.ItemSubCategory == EItemSubCategory::ItemSubCat_Items_Medicine", EditConditionHides))
	FConsumablesStats ConsumablesStats;

	// Чтобы в PrimaryAsset системе было красиво
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		// Type = "MasterItem", Name = AssetName
		return FPrimaryAssetId(TEXT("MasterItem"), GetFName());
	}
};