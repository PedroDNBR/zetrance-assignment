#include "FPSCharacter.h"
#include "Camera/CameraComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "ZetranceTest/Microwave/Microwave.h"
#include "ZetranceTest/Microwave/Grabbable.h"

AFPSCharacter::AFPSCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);

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
	if (bIsHoldingSomething) return;
	AddControllerYawInput(InputValue * MouseSensibilityMultiplier);
}

void AFPSCharacter::LookUp(float InputValue)
{
	LookUpValue = InputValue;
	if (bIsHoldingSomething) return;
	AddControllerPitchInput(InputValue * MouseSensibilityMultiplier);
}

void AFPSCharacter::Hold()
{
	Interact();
}

void AFPSCharacter::Drop()
{
	bIsHoldingSomething = false;
	Grab->ReleaseComponent();
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
		ECC_Visibility //collision channel
	);

	if (HitResult.bBlockingHit)
	{
		AMicrowave* Microwave = Cast<AMicrowave>(HitResult.GetActor());
		if (Microwave)
		{
			Microwave->RotateDoor(LookUpValue * 4);
			bIsHoldingSomething = true;

		}
		else
		{
			bIsHoldingSomething = false;
		}

		AGrabbable* Grabbable = Cast<AGrabbable>(HitResult.GetActor());
		if (Grabbable)
		{
			UPrimitiveComponent* Primitive = Cast<UPrimitiveComponent>(Grabbable);
			if (Primitive)
			{
				Grab->GrabComponentAtLocationWithRotation(
					Primitive,
					"",
					GrabTransform.GetLocation(),
					GrabTransform.Rotator()
				);
			}
		}
		else
		{
			bIsHoldingSomething = false;
		}
	}
	else
	{
		bIsHoldingSomething = false;
	}
}

void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsHoldingSomething)
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

