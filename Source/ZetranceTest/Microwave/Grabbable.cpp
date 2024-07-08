#include "Grabbable.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/ArrowComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

AGrabbable::AGrabbable()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);

	Mesh->SetSimulatePhysics(true);

	ParticlePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("ParticlePosition"));
	ParticlePosition->SetupAttachment(RootComponent);
}

void AGrabbable::PlayParticle()
{
	if (Particle)
	{
		UGameplayStatics::SpawnEmitterAtLocation(
			GetWorld(),
			Particle,
			ParticlePosition->GetComponentTransform()
		); 
	}
	if (SoundEffect)
	{
		UGameplayStatics::PlaySoundAtLocation(
			GetWorld(),
			SoundEffect,
			ParticlePosition->GetComponentLocation()
		);
	}
}

void AGrabbable::BeginPlay()
{
	Super::BeginPlay();
}

void AGrabbable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

