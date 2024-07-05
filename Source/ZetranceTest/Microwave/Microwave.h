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

private:	
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

};
