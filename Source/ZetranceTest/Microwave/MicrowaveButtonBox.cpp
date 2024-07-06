#include "MicrowaveButtonBox.h"

void UMicrowaveButtonBox::Interact()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			1,
			3,
			FColor::Green,
			"Broadcast"
		);
	}
	InteractDelegate.Broadcast();
}
