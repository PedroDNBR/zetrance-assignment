// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "MicrowaveScreenWidget.generated.h"

/**
 * 
 */
UCLASS()
class ZETRANCETEST_API UMicrowaveScreenWidget : public UWidgetComponent
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Timer;

};
