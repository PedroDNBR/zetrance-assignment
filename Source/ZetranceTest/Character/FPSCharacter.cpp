#include "FPSCharacter.h"
#include "Camera/CameraComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/ArrowComponent.h"
#include "ZetranceTest/Microwave/Microwave.h"
#include "ZetranceTest/Microwave/MicrowaveButtonBox.h"
#include "ZetranceTest/Microwave/Grabbable.h"
#include "Components/BoxComponent.h"

AFPSCharacter::AFPSCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);

	Grab = CreateDefaultSubobject<UPhysicsHandleComponent>(TEXT("GrabComponent"));

	Camera->bUsePawnControlRotation = true;
}

void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFPSCharacter::MoveForward(float InputValue)
{
	FVector ForwardDirection = GetActorForwardVector();
	AddMovementInput(ForwardDirection, InputValue);
}

void AFPSCharacter::MoveRight(float InputValue)
{
	FVector RightDirection = GetActorRightVector();
	AddMovementInput(RightDirection, InputValue);
}

void AFPSCharacter::Turn(float InputValue)
{
	if (bLockCamera) return;
	AddControllerYawInput(InputValue * MouseSensibilityMultiplier);
}

void AFPSCharacter::LookUp(float InputValue)
{
	LookUpValue = InputValue;
	if (bLockCamera) return;
	AddControllerPitchInput(InputValue * MouseSensibilityMultiplier);
}

void AFPSCharacter::Hold()
{
	Interact();
}

void AFPSCharacter::Drop()
{
	if (bIsHoldingSomething)
	{
		if (ensure(Grab != nullptr))
		{
			Grab->ReleaseComponent();
			bIsHoldingSomething = false;
		}
	}
	
	if (bLockCamera)
	{
		bLockCamera = false;
	}
}

void AFPSCharacter::Interact()
{
	FVector ViewDir = Camera->GetComponentRotation().Vector();
	ViewDir.Normalize();

	FVector TraceStart = Camera->GetComponentLocation();
	FVector TraceEnd = TraceStart + ViewDir * TraceDistance;

	FHitResult HitResult;

	// Trace from center of screen in direction of aim
	GetWorld()->LineTraceSingleByChannel(
		HitResult,        //result
		TraceStart,    //start
		TraceEnd, //end
		ECC_WorldDynamic //collision channel
	);


	if (HitResult.bBlockingHit)
	{
		UMicrowaveButtonBox* MicrowaveButton = Cast<UMicrowaveButtonBox>(HitResult.GetComponent());
		if (MicrowaveButton)
		{
			MicrowaveButton->Interact();
			return;
		}

		AGrabbable* GrabbableItem = Cast<AGrabbable>(HitResult.GetActor());
		if (GrabbableItem)
		{
			Grab->GrabComponentAtLocationWithRotation(
				HitResult.GetComponent(),
				NAME_None,
				HitResult.GetComponent()->GetComponentLocation(),
				HitResult.GetComponent()->GetComponentRotation()
			);
			bIsHoldingSomething = true;
			return;
		}
		
		AMicrowave* Microwave = Cast<AMicrowave>(HitResult.GetActor());
		if (Microwave)
		{
			Microwave->RotateDoor(LookUpValue * 4);
			bLockCamera = true;
			return;
		}
	}
	else
	{
		bIsHoldingSomething = false;
		bLockCamera = false;
	}
}

void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsHoldingSomething)
	{
		FVector CameraLocation = Camera->GetComponentLocation();
		FQuat CameraRotation = Camera->GetComponentQuat();

		FVector NewGrabLocation = FVector(
			CameraLocation + (CameraRotation.GetForwardVector() * ItemDistanceToCamera)
		);

		Grab->SetTargetLocation(NewGrabLocation);
	}
	

	if (bLockCamera)
	{
		Interact();
	}
}

void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AFPSCharacter::Hold);
	PlayerInputComponent->BindAction("Interact", IE_Released, this, &AFPSCharacter::Drop);

	PlayerInputComponent->BindAxis("MoveFoward", this, &AFPSCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);

	PlayerInputComponent->BindAxis("TurnCamera", this, &AFPSCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &AFPSCharacter::LookUp);

}

