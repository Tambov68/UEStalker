#include "UI/HUD/GameHUDWidget.h"
#include "Components/ProgressBar.h"

void UGameHUDWidget::UpdateVitals(float HP, float Stamina, float Hunger, float Thirst, float Radiation)
{
	if (BarHP)        BarHP->SetPercent(FMath::Clamp(HP, 0.f, 1.f));
	if (BarStamina)   BarStamina->SetPercent(FMath::Clamp(Stamina, 0.f, 1.f));
	if (BarHunger)    BarHunger->SetPercent(FMath::Clamp(Hunger, 0.f, 1.f));
	if (BarThirst)    BarThirst->SetPercent(FMath::Clamp(Thirst, 0.f, 1.f));
	if (BarRadiation) BarRadiation->SetPercent(FMath::Clamp(Radiation, 0.f, 1.f));
}
