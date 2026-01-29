#pragma once

#include "CoreMinimal.h"
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Items/MasterItemStructs.h"
#include "MasterItemDataAsset.generated.h"

/**
 * БАЗОВЫЙ класс.
 * Содержит только то, что есть у ЛЮБОГО предмета (имя, вес, иконка, цена).
 */
UCLASS(BlueprintType, Abstract) // Abstract не даст создать этот ассет напрямую, только наследников
class UMasterItemDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	// Общие детали (Имя, Вес, Категория, Размер)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Common")
	FMasterItemDetails ItemDetails;

	// Торговля нужна всем
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Common")
	FItemTradeConfig TradeConfig;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId(TEXT("MasterItem"), GetFName());
	}
};

/**
 * ОРУЖИЕ (Weapon)
 * Добавляет статы оружия, магазины, прочность.
 */
UCLASS(BlueprintType)
class UWeaponDataAsset : public UMasterItemDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Weapon Stats")
	FItemWeaponsStatsConfig WeaponStatsConfig;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Weapon Stats")
	FItemDurabilityConfig DurabilityConfig;

	// Если нужно, сюда можно добавить совместимые прицелы и т.д.
};

/**
 * ЭКИПИРОВКА (Armor, Helmet, Backpack)
 * Добавляет защиту, прочность, слоты контейнеров.
 */
UCLASS(BlueprintType)
class UOutfitDataAsset : public UMasterItemDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Outfit Stats")
	FItemOutfitStatsConfig OutfitStatsConfig;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Outfit Stats")
	FItemDurabilityConfig DurabilityConfig;
};

/**
 * РАСХОДНИКИ (Food, Meds)
 * Добавляет эффекты лечения/еды.
 */
UCLASS(BlueprintType)
class UConsumableDataAsset : public UMasterItemDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Consumable Stats")
	FConsumablesStats ConsumablesStats;
};

/**
 * ГАДЖЕТЫ (PDA, Detectors)
 * Добавляет заряд батареи.
 */
UCLASS(BlueprintType)
class UUsableItemDataAsset : public UMasterItemDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Device Stats")
	FItemChargeConfig ChargeConfig;
};

/**
 * МАГАЗИНЫ / АТТАЧМЕНТЫ
 */
UCLASS(BlueprintType)
class UAttachmentDataAsset : public UMasterItemDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item|Attachment")
	FItemMagazineConfig MagazineConfig;
};