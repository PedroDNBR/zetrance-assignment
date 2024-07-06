#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSCharacter.generated.h"

UCLASS()
class ZETRANCETEST_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AFPSCharacter();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	class UPhysicsHandleComponent* Grab;

	UPROPERTY(EditAnywhere)
	class UArrowComponent* GrabArrow;


public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	const float TraceDistance = 160.f;
	const bool DrawDebugLine = true;

	UPROPERTY(EditAnywhere)
	float MouseSensibilityMultiplier = 1.f;

	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera;

	void MoveForward(float InputValue);
	void MoveRight(float InputValue);

	void Turn(float InputValue);
	void LookUp(float InputValue);
	
	void Hold();
	void Drop();

	void Interact();

	float LookUpValue = 0.f;

	bool bIsHoldingSomething = false;
};
