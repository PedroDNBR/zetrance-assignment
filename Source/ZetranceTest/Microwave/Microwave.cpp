#include "Microwave.h"
#include "Components/WidgetComponent.h"
#include "Components/PointLightComponent.h"

AMicrowave::AMicrowave()
{
	PrimaryActorTick.bCanEverTick = true;

	MicrowaveBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MicrowaveBody"));
	SetRootComponent(MicrowaveBody);

	MicrowaveDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MicrowaveDoor"));
	MicrowaveDoor->SetupAttachment(RootComponent);

	MicrowavePlate = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MicrowavePlate"));
	MicrowavePlate->SetupAttachment(RootComponent);

	MicrowaveScreenWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("MicrowaveScreenWidget"));
	MicrowaveScreenWidget->SetupAttachment(RootComponent);

	MicrowaveLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("MicrowaveLight"));
	MicrowaveLight->SetupAttachment(RootComponent);
}

void AMicrowave::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMicrowave::ToggleLight(bool bEnabled)
{
	if (bEnabled)
	{
		MicrowaveLight->SetIntensity(OnLightIntensity);
		MicrowaveBody->SetMaterial(LightMaterialIndex, LightOnMaterial);
	}
	else
	{
		MicrowaveLight->SetIntensity(0);
		MicrowaveBody->SetMaterial(LightMaterialIndex, LightOffMaterial);
	}
}

void AMicrowave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMicrowave::RotateDoor(float InputValue)
{
	FRotator Rotation = FRotator(
		0, 
		FMath::Clamp(
			float (MicrowaveDoor->GetRelativeRotation().Yaw) + InputValue, 
			MinDoorRotation, 
			MaxDoorRotation
		), 
		0
	);
	MicrowaveDoor->SetRelativeRotation(Rotation);
	ToggleLight(MicrowaveDoor->GetRelativeRotation().Yaw >= .001f);
}

