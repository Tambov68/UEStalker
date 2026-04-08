#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameHUDWidget.generated.h"

class UMiniMapWidget;
class UProgressBar;
class UTextBlock;

UCLASS()
class UESTALKER_API UGameHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta=(BindWidgetOptional), BlueprintReadOnly)
	TObjectPtr<UMiniMapWidget> WBMiniMap = nullptr;

	// === Vital Bars ===
	UPROPERTY(meta=(BindWidgetOptional), BlueprintReadOnly)
	TObjectPtr<UProgressBar> BarHP = nullptr;

	UPROPERTY(meta=(BindWidgetOptional), BlueprintReadOnly)
	TObjectPtr<UProgressBar> BarStamina = nullptr;

	UPROPERTY(meta=(BindWidgetOptional), BlueprintReadOnly)
	TObjectPtr<UProgressBar> BarHunger = nullptr;

	UPROPERTY(meta=(BindWidgetOptional), BlueprintReadOnly)
	TObjectPtr<UProgressBar> BarThirst = nullptr;

	UPROPERTY(meta=(BindWidgetOptional), BlueprintReadOnly)
	TObjectPtr<UProgressBar> BarRadiation = nullptr;

	/** Set all bars at once (values 0..1) */
	UFUNCTION(BlueprintCallable, Category="HUD")
	void UpdateVitals(float HP, float Stamina, float Hunger, float Thirst, float Radiation = 0.f);
};
