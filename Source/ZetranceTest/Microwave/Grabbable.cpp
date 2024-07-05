#include "Grabbable.h"

AGrabbable::AGrabbable()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
}

void AGrabbable::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGrabbable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

