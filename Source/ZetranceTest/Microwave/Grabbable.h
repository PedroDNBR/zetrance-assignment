#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UParticleSystem* Particle;

	UPROPERTY(EditAnywhere)
	class UArrowComponent* ParticlePosition;

	UPROPERTY(EditAnywhere)
	class USoundCue* SoundEffect;


	UFUNCTION()
	void PlayParticle();

protected:
	virtual void BeginPlay() override;

private:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

public:
	FORCEINLINE UStaticMeshComponent* GetMesh() const { return Mesh; }


};
