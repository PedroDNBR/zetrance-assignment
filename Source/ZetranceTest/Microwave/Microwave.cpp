#include "Microwave.h"
#include "MicrowaveButtonBox.h"
#include "Grabbable.h"
#include "ScreenTimer.h"
#include "Components/WidgetComponent.h"
#include "Components/TextBlock.h"
#include "Components/PointLightComponent.h"
#include "Components/BoxComponent.h"
#include "Components/AudioComponent.h"
#include "Engine/TriggerBox.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Sound/SoundCue.h"

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

	OneButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("OneButton"));
	OneButton->SetupAttachment(RootComponent);
	OneButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	OneButton->SetBoxExtent(FVector(.2f, 1.2f, .6f));

	TwoButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("TwoButton"));
	TwoButton->SetupAttachment(RootComponent);
	TwoButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	TwoButton->SetBoxExtent(FVector(.2f, 1.2f, .6f));

	ThreeButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("ThreeButton"));
	ThreeButton->SetupAttachment(RootComponent);
	ThreeButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	ThreeButton->SetBoxExtent(FVector(.2f, 1.2f, .6f));

	FourButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("FourButton"));
	FourButton->SetupAttachment(RootComponent);
	FourButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	FourButton->SetBoxExtent(FVector(.2f, 1.2f, .6f));

	FiveButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("FiveButton"));
	FiveButton->SetupAttachment(RootComponent);
	FiveButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	FiveButton->SetBoxExtent(FVector(.2f, 1.2f, .6f));

	SixButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("SixButton"));
	SixButton->SetupAttachment(RootComponent);
	SixButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	SixButton->SetBoxExtent(FVector(.2f, 1.2f, .6f));

	SevenButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("SevenButton"));
	SevenButton->SetupAttachment(RootComponent);
	SevenButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	SevenButton->SetBoxExtent(FVector(.2f, 1.2f, .6f));

	EightButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("EightButton"));
	EightButton->SetupAttachment(RootComponent);
	EightButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	EightButton->SetBoxExtent(FVector(.2f, 1.2f, .6f));

	NineButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("NineButton"));
	NineButton->SetupAttachment(RootComponent);
	NineButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	NineButton->SetBoxExtent(FVector(.2f, 1.2f, .6f));

	ZeroButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("ZeroButton"));
	ZeroButton->SetupAttachment(RootComponent);
	ZeroButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	ZeroButton->SetBoxExtent(FVector(.2f, 1.2f, .6f));

	MugCakeButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("MugCakeButton"));
	MugCakeButton->SetupAttachment(RootComponent);
	MugCakeButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	MugCakeButton->SetBoxExtent(FVector(.2f, 1.2f, .6f));

	MeltSoftenButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("MeltSoftenButton"));
	MeltSoftenButton->SetupAttachment(RootComponent);
	MeltSoftenButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	MeltSoftenButton->SetBoxExtent(FVector(.2f, 1.2f, .6f));

	ReheatPlateButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("ReheatPlateButton"));
	ReheatPlateButton->SetupAttachment(RootComponent);
	ReheatPlateButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	ReheatPlateButton->SetBoxExtent(FVector(.2f, 1.2f, .6f));

	ReheatBeverageButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("ReheatBeverageButton"));
	ReheatBeverageButton->SetupAttachment(RootComponent);
	ReheatBeverageButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	ReheatBeverageButton->SetBoxExtent(FVector(.2f, 1.2f, .6f));

	PotatoButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("PotatoButton"));
	PotatoButton->SetupAttachment(RootComponent);
	PotatoButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	PotatoButton->SetBoxExtent(FVector(.2f, 1.2f, .6f));

	VegetablesButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("VegetablesButton"));
	VegetablesButton->SetupAttachment(RootComponent);
	VegetablesButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	VegetablesButton->SetBoxExtent(FVector(.2f, 1.2f, .6f));

	RiceQuinoaButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("RiceQuinoaButton"));
	RiceQuinoaButton->SetupAttachment(RootComponent);
	RiceQuinoaButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	RiceQuinoaButton->SetBoxExtent(FVector(.2f, 1.2f, .6f));

	PastaButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("PastaButton"));
	PastaButton->SetupAttachment(RootComponent);
	PastaButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	PastaButton->SetBoxExtent(FVector(.2f, 1.2f, .6f));

	MeatButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("MeatButton"));
	MeatButton->SetupAttachment(RootComponent);
	MeatButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	MeatButton->SetBoxExtent(FVector(.2f, 1.2f, .6f));

	PoultryFishButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("PoultryFishButton"));
	PoultryFishButton->SetupAttachment(RootComponent);
	PoultryFishButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	PoultryFishButton->SetBoxExtent(FVector(.2f, 1.2f, .6f));

	PowerLevelButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("PowerLevelButton"));
	PowerLevelButton->SetupAttachment(RootComponent);
	PowerLevelButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	PowerLevelButton->SetBoxExtent(FVector(.2f, 1.2f, .6f));

	
	SetClockButton = CreateDefaultSubobject<UMicrowaveButtonBox>(TEXT("SetClockButton"));
	SetClockButton->SetupAttachment(RootComponent);
	SetClockButton->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	SetClockButton->SetBoxExtent(FVector(.2f, 1.2f, .6f));

	InsideMicrowaveCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("InsideMicrowaveCollision"));
	InsideMicrowaveCollision->SetupAttachment(RootComponent);

	MicrowaveLoopComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("MicrowaveLoopComponent"));
}

void AMicrowave::PlayBeep()
{
	if (MicrowaveBeep)
	{
		UGameplayStatics::PlaySoundAtLocation(
			GetWorld(),
			MicrowaveBeep,
			GetActorLocation()
		);
	}
}

void AMicrowave::BeginPlay()
{
	Super::BeginPlay();
	
	ClockTime = UKismetMathLibrary::Now();

	GetWorldTimerManager().SetTimer(
		ClockTimeHandle,
		this,
		&AMicrowave::PassSecond,
		1
	);

	CurrentPower = SavedPower;

	StartButton->InteractDelegate.AddDynamic(this, &AMicrowave::TurnOnMicrowave);
	StopButton->InteractDelegate.AddDynamic(this, &AMicrowave::Stop);

	OneButton->InteractDelegate.AddDynamic(this, &AMicrowave::One);
	TwoButton->InteractDelegate.AddDynamic(this, &AMicrowave::Two);
	ThreeButton->InteractDelegate.AddDynamic(this, &AMicrowave::Three);
	FourButton->InteractDelegate.AddDynamic(this, &AMicrowave::Four);
	FiveButton->InteractDelegate.AddDynamic(this, &AMicrowave::Five);
	SixButton->InteractDelegate.AddDynamic(this, &AMicrowave::Six);
	SevenButton->InteractDelegate.AddDynamic(this, &AMicrowave::Seven);
	EightButton->InteractDelegate.AddDynamic(this, &AMicrowave::Eight);
	NineButton->InteractDelegate.AddDynamic(this, &AMicrowave::Nine);
	ZeroButton->InteractDelegate.AddDynamic(this, &AMicrowave::Zero);

	MugCakeButton->InteractDelegate.AddDynamic(this, &AMicrowave::MugCake);
	MeltSoftenButton->InteractDelegate.AddDynamic(this, &AMicrowave::MeltSoften);
	ReheatPlateButton->InteractDelegate.AddDynamic(this, &AMicrowave::ReheatPlate);
	ReheatBeverageButton->InteractDelegate.AddDynamic(this, &AMicrowave::ReheatBeverage);
	PotatoButton->InteractDelegate.AddDynamic(this, &AMicrowave::Potato);
	VegetablesButton->InteractDelegate.AddDynamic(this, &AMicrowave::Vegetables);
	RiceQuinoaButton->InteractDelegate.AddDynamic(this, &AMicrowave::RiceQuinoa);
	PastaButton->InteractDelegate.AddDynamic(this, &AMicrowave::Pasta);
	MeatButton->InteractDelegate.AddDynamic(this, &AMicrowave::Meat);
	PoultryFishButton->InteractDelegate.AddDynamic(this, &AMicrowave::PoultryFish);

	PowerLevelButton->InteractDelegate.AddDynamic(this, &AMicrowave::PowerLevel);
	SetClockButton->InteractDelegate.AddDynamic(this, &AMicrowave::SetClock);

	InsideMicrowaveCollision->OnComponentBeginOverlap.AddDynamic(this, &AMicrowave::SomethingInTheMicrowave);
	InsideMicrowaveCollision->OnComponentEndOverlap.AddDynamic(this, &AMicrowave::SomethingExitedTheMicrowave);

}

void AMicrowave::SomethingInTheMicrowave(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AGrabbable* Grabbable = Cast<AGrabbable>(OtherActor);
	if (Grabbable)
	{
		ActorInTheMicrowave = Grabbable;
	}
}

void AMicrowave::SomethingExitedTheMicrowave(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (ActorInTheMicrowave != nullptr)
	{
		ActorInTheMicrowave = nullptr;
	}
}

void AMicrowave::SetNewClockTimeString(int NewNumber)
{
	if (NewNumber >= 0)
	{
		NewClockTimeString[NewClockTimeIndex] = FString::Printf(TEXT("%i"), NewNumber)[0];
		NewClockTimeIndex++;

		if (NewClockTimeIndex > 3) NewClockTimeIndex = 0;
	}
	else
	{
		NewClockTimeString = ClockTime.ToString(TEXT("%h%M"));
	}
}

void AMicrowave::PassSecond()
{
	FTimespan modifyTime = FTimespan::FromSeconds(1);
	ClockTime += modifyTime;

	GetWorldTimerManager().SetTimer(
		ClockTimeHandle,
		this,
		&AMicrowave::PassSecond,
		1
	);
}

void AMicrowave::SetPowerAndTimeAndStart(int Power, int Time)
{
	PlayBeep();
	if (bIsHeating || IsDoorOpen() || SecondsTimer > 0) return;

	SecondsTimer = Time;
	CurrentPower = Power;

	TurnOnMicrowave();

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
	PlayBeep();

	if (bEditingPower)
	{
		SavedPower = CurrentPower;
		bEditingPower = false;
		return;
	}

	if (bEditingClock)
	{
		FString MinutesInString = NewClockTimeString.Right(2);
		FString HourInString = FString("0");

		if (NewClockTimeString.Len() == 3)
		{
			HourInString = NewClockTimeString.Left(1);
		}
		if (NewClockTimeString.Len() == 4)
		{
			HourInString = NewClockTimeString.Left(2);
		}

		int32 newMinute = FCString::Atoi(*MinutesInString);
		int32 newHour = FCString::Atoi(*HourInString);

		if (newHour > 12 || newMinute > 59)
		{
			SetNewClockTimeString(-1);
			bEditingClock = false;
			return;
		}

		FDateTime NewDateTime(
			ClockTime.GetYear(),
			ClockTime.GetMonth(),
			ClockTime.GetDay(),
			newHour,
			newMinute,
			ClockTime.GetSecond(),
			ClockTime.GetMillisecond()
		);

		ClockTime = NewDateTime;

		bEditingClock = false;

		return;
	}

	if (IsDoorOpen()) return;

	if (bIsHeating || SecondsTimer <= 0)
	{
		SecondsTimer += 30;
	}
	bEditingTimer = true;
	if (MicrowaveLoopComponent && MicrowaveLoop)
	{
		MicrowaveLoopComponent->SetSound(MicrowaveLoop);
		MicrowaveLoopComponent->Play();
	}

	Heat();

	StartSecondsTimer();
}

void AMicrowave::Heat()
{
	bIsHeating = true;
	ToggleLight(true);
	if (ActorInTheMicrowave && ActorInTheMicrowave != nullptr)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				15.f,
				FColor::Green,
				"AAAA"
			);
		}
		ActorInTheMicrowave->PlayParticle();
	}
}

void AMicrowave::TurnOffMicrowave()
{
	bIsHeating = false;
	SecondsTimer = 0;
	CurrentPower = SavedPower;
	if (MicrowaveLoopComponent && MicrowaveLoop)
	{
		MicrowaveLoopComponent->Stop();
	}
	if (IsDoorOpen()) return;
	ToggleLight(false);
}

void AMicrowave::PauseMicrowave()
{
	if (MicrowaveLoopComponent && MicrowaveLoop)
	{
		MicrowaveLoopComponent->Stop();
	}
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
		if (MicrowaveFinishBeep)
		{
			UGameplayStatics::PlaySoundAtLocation(
				GetWorld(),
				MicrowaveFinishBeep,
				GetActorLocation()
			);
		}
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
	PlayBeep();
	if (bEditingTimer)
	{
		bEditingTimer = false;
	}
	if (bEditingPower)
	{
		bEditingPower = false;
	}
	if (bEditingClock)
	{
		bEditingClock = false;
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

FString AMicrowave::TimeToIntStringSequentiated(int Time)
{
	FString TimerDateTimeFormatted = FTimespan::FromSeconds(Time).ToString();
	FString TimerhhmmFormatted = TimerDateTimeFormatted.Mid(4, 5);

	FString SecondsString = TimerhhmmFormatted.Right(2);
	FString MinutesString = TimerhhmmFormatted.Left(2);


	FString MinutesSecondsInSequence = FString::Printf(TEXT("%s%s"), *MinutesString, *SecondsString);

	return MinutesSecondsInSequence;
}

int AMicrowave::StringTimeToSeconds(FString TimeInString)
{
	FString SecondsAfterAdded = TimeInString.Right(2);
	FString MinutesAfterAdded = FString("0");

	if (TimeInString.Len() == 3)
	{
		MinutesAfterAdded = TimeInString.Left(1);
	}
	if (TimeInString.Len() == 4)
	{
		MinutesAfterAdded = TimeInString.Left(2);
	}

	int SecondsInInt = FCString::Atoi(*SecondsAfterAdded);
	int MinutesInInt = FCString::Atoi(*MinutesAfterAdded);

	return (MinutesInInt * 60) + SecondsInInt;
}

void AMicrowave::AddToSeconds(int Number)
{
	PlayBeep();
	if (bEditingClock) 
	{
		SetNewClockTimeString(Number);
	}
	else if (bEditingPower)
	{
		if (CurrentPower == 10 && Number == 0)
		{
			CurrentPower = 100;
		}
		else if (Number > 0)
		{
			CurrentPower = Number * 10;
		}
	}
	else
	{
		if (SecondsTimer <= 0)
		{
			bEditingTimer = true;
		}

		if (SecondsTimer <= 0)
		{
			SecondsTimer = Number;
		}
		else
		{
			FString StringIntTimeSequentiated = TimeToIntStringSequentiated(SecondsTimer);

			int MinutesSecondsInSequenceInt = FCString::Atoi(*StringIntTimeSequentiated);

			FString NumberAdded = FString::Printf(TEXT("%i%i"), MinutesSecondsInSequenceInt, Number);

			SecondsTimer = StringTimeToSeconds(NumberAdded);
		}
	}
}

void AMicrowave::One()
{
	AddToSeconds(1);
}

void AMicrowave::Two()
{
	AddToSeconds(2);
}

void AMicrowave::Three()
{
	AddToSeconds(3);
}

void AMicrowave::Four()
{
	AddToSeconds(4);
}

void AMicrowave::Five()
{
	AddToSeconds(5);
}

void AMicrowave::Six()
{
	AddToSeconds(6);
}

void AMicrowave::Seven()
{
	AddToSeconds(7);
}

void AMicrowave::Eight()
{
	AddToSeconds(8);
}

void AMicrowave::Nine()
{
	AddToSeconds(9);
}

void AMicrowave::Zero()
{
	AddToSeconds(0);
}

void AMicrowave::MugCake()
{
	SetPowerAndTimeAndStart(100, 120);
}

void AMicrowave::MeltSoften()
{
	SetPowerAndTimeAndStart(50,300);
}

void AMicrowave::ReheatPlate()
{
	SetPowerAndTimeAndStart(100,60);
}

void AMicrowave::ReheatBeverage()
{
	SetPowerAndTimeAndStart(100,30);
}

void AMicrowave::Potato()
{
	SetPowerAndTimeAndStart(100, 660);
}

void AMicrowave::Vegetables()
{
	SetPowerAndTimeAndStart(100, 480);
}

void AMicrowave::RiceQuinoa()
{
	SetPowerAndTimeAndStart(100,90);
}

void AMicrowave::Pasta()
{
	SetPowerAndTimeAndStart(100,600);
}

void AMicrowave::Meat()
{
	SetPowerAndTimeAndStart(30,600);
}

void AMicrowave::PoultryFish()
{
	SetPowerAndTimeAndStart(30, 480);
}

void AMicrowave::PowerLevel()
{
	PlayBeep();
	if (SecondsTimer > 0 || bIsHeating || bEditingClock) return;

	bEditingTimer = false;
	bEditingPower = true;
	bEditingClock = false;
}

void AMicrowave::SetClock()
{
	PlayBeep();
	if (bEditingClock || SecondsTimer > 0 || bIsHeating || bEditingPower) return;

	NewClockTimeIndex = 0;

	SetNewClockTimeString(-1);

	bEditingTimer = false;
	bEditingPower = false;
	bEditingClock = true;

}

void AMicrowave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsHeating)
	{
		MicrowavePlate->SetRelativeRotation(
			FRotator(0, MicrowavePlate->GetRelativeRotation().Yaw + (10 * DeltaTime), 0)
		);

		if (ActorInTheMicrowave && ActorInTheMicrowave != nullptr)
		{
			ActorInTheMicrowave->PlayParticle();
		}
	}

	if (bEditingPower)
	{
		int PowerLevelDivided = CurrentPower / 10;
		UScreenTimer* ScreenTimer = Cast<UScreenTimer>(MicrowaveScreenWidget->GetWidget());
		if (ScreenTimer)
		{
			ScreenTimer->Timer->SetText(FText::FromString(FString::Printf(TEXT("PL:%i"), PowerLevelDivided)));
		}
	}
	else if (bEditingTimer)
	{
		FString TimerDateTimeFormatted = FTimespan::FromSeconds(SecondsTimer).ToString();
		FString TimerhhmmFormatted = TimerDateTimeFormatted.Mid(4, 5);

		UScreenTimer* ScreenTimer = Cast<UScreenTimer>(MicrowaveScreenWidget->GetWidget());
		if (ScreenTimer)
		{
			ScreenTimer->Timer->SetText(FText::FromString(TimerhhmmFormatted));
		}
	}
	else if (bEditingClock)
	{
		FString MinutesInString = NewClockTimeString.Right(2);
		FString HourInString = FString("0");

		if (NewClockTimeString.Len() == 3)
		{
			HourInString = NewClockTimeString.Left(1);
		}

		if (NewClockTimeString.Len() == 4)
		{
			HourInString = NewClockTimeString.Left(2);
		}

		UScreenTimer* ScreenTimer = Cast<UScreenTimer>(MicrowaveScreenWidget->GetWidget());
		if (ScreenTimer)
		{
			ScreenTimer->Timer->SetText(FText::FromString(FString::Printf(TEXT("%s:%s"), *HourInString, *MinutesInString)));
		}
	}

	if (!bEditingPower && !bIsHeating && !bEditingTimer && !bEditingClock && SecondsTimer <= 0)
	{
		UScreenTimer* ScreenTimer = Cast<UScreenTimer>(MicrowaveScreenWidget->GetWidget());
		if (ScreenTimer)
		{
			ScreenTimer->Timer->SetText(FText::FromString(ClockTime.ToString(TEXT("%h:%M"))));
		}
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
		if (SecondsTimer <= 0)
		{
			bEditingTimer = false;
		}
	}
	ToggleLight(IsDoorOpen());
}
