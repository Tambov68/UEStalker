#include "World/RadiationZoneActor.h"
#include "Components/SphereComponent.h"
#include "Character/MasterCharacter.h"

ARadiationZoneActor::ARadiationZoneActor()
{
	PrimaryActorTick.bCanEverTick = true;

	RadiationSphere = CreateDefaultSubobject<USphereComponent>(TEXT("RadiationSphere"));
	RootComponent = RadiationSphere;
	RadiationSphere->SetSphereRadius(ZoneRadius);
	RadiationSphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	RadiationSphere->SetGenerateOverlapEvents(true);
	RadiationSphere->ShapeColor = FColor(80, 200, 30);
}

void ARadiationZoneActor::BeginPlay()
{
	Super::BeginPlay();
	RadiationSphere->SetSphereRadius(ZoneRadius);
}

void ARadiationZoneActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TArray<AActor*> Overlapping;
	GetOverlappingActors(Overlapping, AMasterCharacter::StaticClass());

	for (AActor* Actor : Overlapping)
	{
		AMasterCharacter* Character = Cast<AMasterCharacter>(Actor);
		if (IsValid(Character) && !Character->bIsDead)
		{
			Character->Radiation = FMath::Clamp(
				Character->Radiation + RadiationPerSecond * DeltaTime,
				0.f,
				Character->MaxRadiation
			);
		}
	}
}
