#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "MicrowaveButtonBox.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInteract);

UCLASS()
class ZETRANCETEST_API UMicrowaveButtonBox : public UBoxComponent
{
	GENERATED_BODY()

public:
	FInteract InteractDelegate;

	void Interact();
};
