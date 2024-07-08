#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "MicrowaveButtonBox.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInteract);

UCLASS(BlueprintType, Blueprintable, ClassGroup = "Collision", hidecategories = (Object, LOD, Lighting, TextureStreaming), editinlinenew, meta = (DisplayName = "Microwave Button Box Collision", BlueprintSpawnableComponent))
class ZETRANCETEST_API UMicrowaveButtonBox : public UBoxComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FInteract InteractDelegate;

	UFUNCTION(BlueprintCallable)
	void Interact();
};
