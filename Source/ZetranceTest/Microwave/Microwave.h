#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Microwave.generated.h"

UCLASS()
class ZETRANCETEST_API AMicrowave : public AActor
{
	GENERATED_BODY()
	
public:	
	AMicrowave();
	virtual void Tick(float DeltaTime) override;

	void RotateDoor(float InputValue);

	UPROPERTY(EditAnywhere)
	class UBoxComponent* InsideMicrowaveCollision;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class AGrabbable* ActorInTheMicrowave;

protected:
	UPROPERTY(EditAnywhere)
	class USoundCue* MicrowaveBeep;

	UPROPERTY(EditAnywhere)
	class USoundCue* MicrowaveFinishBeep;

	UPROPERTY(EditAnywhere)
	class USoundCue* MicrowaveLoop;

	UPROPERTY(EditAnywhere)
	class UAudioComponent* MicrowaveLoopComponent;

	void PlayBeep();

	virtual void BeginPlay() override;

	UFUNCTION() 
	void SomethingInTheMicrowave(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void SomethingExitedTheMicrowave(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	

	int MaxPower = 100;
	int MinPower = 40;

	int CurrentPower = 0;

	int SavedPower = 100;

	int SecondsTimer = 0;

	bool bIsHeating = false;

	FString TimeToIntStringSequentiated(int Time);

	int StringTimeToSeconds(FString TimeInString);

private:
	void SetNewClockTimeString(int NewNumber);
	FString NewClockTimeString;
	int NewClockTimeIndex = 0;

	FDateTime ClockTime;


	FTimerHandle ClockTimeHandle;

	void PassSecond();

	void SetPowerAndTimeAndStart(int Power, int Time);

	bool bEditingTimer = false;

	bool bEditingPower = false;

	bool bEditingClock = false;

	FTimerHandle TimerHandle;

	UPROPERTY(EditAnywhere)
	int LightMaterialIndex = 2;

	UPROPERTY(EditAnywhere)
	class UMaterial* LightOnMaterial;

	UPROPERTY(EditAnywhere)
	class UMaterial* LightOffMaterial;

	UPROPERTY(EditAnywhere)
	float OnLightIntensity = 200.f;

	UPROPERTY(EditAnywhere)
	float MaxDoorRotation = 120.f;
	UPROPERTY(EditAnywhere)
	float MinDoorRotation = 0.f;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MicrowaveBody;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MicrowaveDoor;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MicrowavePlate;

	UPROPERTY(EditAnywhere)
	class UWidgetComponent* MicrowaveScreenWidget;

	UPROPERTY(EditAnywhere)
	class UPointLightComponent* MicrowaveLight;

	void ToggleLight(bool bEnabled);

	bool IsDoorOpen();

	void AddToSeconds(int Number);

	UFUNCTION()
	void TurnOnMicrowave();

	void Heat();

	UFUNCTION()
	void TurnOffMicrowave();

	UFUNCTION()
	void PauseMicrowave();

	void SubtractSecondsFromTimer();
	void StartSecondsTimer();

	UFUNCTION()
	void Stop();

	void PauseTimer();

	UFUNCTION()
	void One();

	UFUNCTION()
	void Two();

	UFUNCTION()
	void Three();

	UFUNCTION()
	void Four();

	UFUNCTION()
	void Five();

	UFUNCTION()
	void Six();

	UFUNCTION()
	void Seven();

	UFUNCTION()
	void Eight();

	UFUNCTION()
	void Nine();

	UFUNCTION()
	void Zero();

	UFUNCTION()
	void MugCake();

	UFUNCTION()
	void MeltSoften();

	UFUNCTION()
	void ReheatPlate();

	UFUNCTION()
	void ReheatBeverage();

	UFUNCTION()
	void Potato();

	UFUNCTION()
	void Vegetables();

	UFUNCTION()
	void RiceQuinoa();

	UFUNCTION()
	void Pasta();

	UFUNCTION()
	void Meat();

	UFUNCTION()
	void PoultryFish();

	UFUNCTION()
	void PowerLevel();

	UFUNCTION()
	void SetClock();

	/*
	* Buttons 
	*/
	UPROPERTY(EditAnywhere)
	class UMicrowaveButtonBox* StartButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* StopButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* OneButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* TwoButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* ThreeButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* FourButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* FiveButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* SixButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* SevenButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* EightButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* NineButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* ZeroButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* MugCakeButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* MeltSoftenButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* ReheatPlateButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* ReheatBeverageButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* PotatoButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* VegetablesButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* RiceQuinoaButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* PastaButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* MeatButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* PoultryFishButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* PowerLevelButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* SetClockButton;

};
