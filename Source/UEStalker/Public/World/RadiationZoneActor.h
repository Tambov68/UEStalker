#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RadiationZoneActor.generated.h"

class USphereComponent;
class UParticleSystemComponent;

UCLASS()
class UESTALKER_API ARadiationZoneActor : public AActor
{
	GENERATED_BODY()

public:
	ARadiationZoneActor();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<USphereComponent> RadiationSphere = nullptr;

public:
	/** Radiation added per second to characters inside the zone */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Radiation", meta=(ClampMin="0.0"))
	float RadiationPerSecond = 5.f;

	/** Radius in cm */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Radiation", meta=(ClampMin="0.0"))
	float ZoneRadius = 500.f;
};
