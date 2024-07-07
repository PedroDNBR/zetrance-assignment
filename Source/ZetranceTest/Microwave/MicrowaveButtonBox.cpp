#include "MicrowaveButtonBox.h"

void UMicrowaveButtonBox::Interact()
{
	InteractDelegate.Broadcast();
}
