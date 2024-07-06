#include "Microwave.h"
#include "MicrowaveButtonBox.h"
#include "MicrowaveScreenWidget.h"
#include "ScreenTimer.h"
#include "Components/WidgetComponent.h"
#include "Components/TextBlock.h"
#include "Components/PointLightComponent.h"
#include "Components/BoxComponent.h"
#include "Engine/TriggerBox.h"
#include "Kismet/GameplayStatics.h"

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

	StartButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("TurnOnButton"));
	StartButton->SetupAttachment(RootComponent);
	StartButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);

	StopButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("StopButton"));
	StopButton->SetupAttachment(RootComponent);
	StopButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);

	
}

void AMicrowave::BeginPlay()
{
	Super::BeginPlay();

	StartButton->InteractDelegate.AddDynamic(this, &AMicrowave::TurnOnMicrowave);

	StopButton->InteractDelegate.AddDynamic(this, &AMicrowave::Stop);

	

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

bool AMicrowave::IsDoorOpen()
{
	return MicrowaveDoor->GetRelativeRotation().Yaw >= .001f;
}

void AMicrowave::TurnOnMicrowave()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.f,
			FColor::Green,
			"On"
		);
	}
	if (IsDoorOpen()) return;

	if (bIsHeating || SecondsTimer <= 0)
	{
		SecondsTimer += 30;
	}
	Heat();

	StartSecondsTimer();
}

void AMicrowave::Heat()
{
	bIsHeating = true;
	ToggleLight(true);
}

void AMicrowave::TurnOffMicrowave()
{
	bIsHeating = false;
	SecondsTimer = 0;
	if (IsDoorOpen()) return;
	ToggleLight(false);
}

void AMicrowave::PauseMicrowave()
{
	bIsHeating = false;
	PauseTimer();
	ToggleLight(false);

}

void AMicrowave::SubtractSecondsFromTimer()
{
	SecondsTimer--;
	if (SecondsTimer <= 0)
	{
		TurnOffMicrowave();
	}
	else
	{
		StartSecondsTimer();
	}
}

void AMicrowave::StartSecondsTimer()
{
	GetWorldTimerManager().SetTimer(
		TimerHandle,
		this,
		&AMicrowave::SubtractSecondsFromTimer,
		1
	);
}

void AMicrowave::Stop()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.f,
			FColor::Green,
			"off"
		);
	}
	if (bIsHeating)
	{
		PauseMicrowave();
	}
	else
	{
		TurnOffMicrowave();
	}
}

void AMicrowave::PauseTimer()
{
	GetWorldTimerManager().PauseTimer(TimerHandle);
}





void AMicrowave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsHeating)
	{
		MicrowavePlate->SetRelativeRotation(
			FRotator(0, MicrowavePlate->GetRelativeRotation().Yaw + (10 * DeltaTime), 0)
		);
	}

	FString TimerDateTimeFormatted = FTimespan::FromSeconds(SecondsTimer).ToString();
	FString TimerhhmmFormatted = TimerDateTimeFormatted.Mid(4, 5);

	UScreenTimer* ScreenTimer = Cast<UScreenTimer>(MicrowaveScreenWidget->GetWidget());
	if (ScreenTimer)
	{
		ScreenTimer->Timer->SetText(FText::FromString(TimerhhmmFormatted));
	}
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
	if (IsDoorOpen())
	{
		PauseMicrowave();
	}
	ToggleLight(IsDoorOpen());
}
