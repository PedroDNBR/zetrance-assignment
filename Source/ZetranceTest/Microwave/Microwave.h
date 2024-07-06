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

protected:
	virtual void BeginPlay() override;

	int MaxPower = 100;
	int MinPower = 40;

	int CurrentPower;

	int SavedPower;

	int SecondsTimer = 0;
	int MinutesTimer = 0;

	bool bIsHeating = false;

private:


	FTimerHandle TimerHandle;

	UPROPERTY(EditAnywhere)
	int32 LightMaterialIndex = 2;

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

	

	/*
	* Buttons 
	*/
	UPROPERTY(EditAnywhere)
	class UMicrowaveButtonBox* StartButton;

	UPROPERTY(EditAnywhere)
	UMicrowaveButtonBox* StopButton;

	

};
