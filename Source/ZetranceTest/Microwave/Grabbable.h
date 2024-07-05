#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grabbable.generated.h"

UENUM(BlueprintType)
enum class EType : uint8
{
	ET_SafeForMicrowave UMETA(DisplayName = "Safe For Microwave"),
	ET_Other UMETA(DisplayName = "Other"),
	ET_MAX UMETA(DisplayName = "DefaultMAX")
};

UCLASS()
class ZETRANCETEST_API AGrabbable : public AActor
{
	GENERATED_BODY()
	
public:	
	AGrabbable();
	UPROPERTY(EditAnywhere)
	EType Type;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

};
