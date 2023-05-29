#pragma once

#include <CoreMinimal.h>
#include <Engine.h>

class GEngineInterface
{
	static void AddOnScreenDebugMessage()
	{
		if (GEngine != nullptr)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				15.f,
				FColor::Blue,
				FString::Printf(TEXT("Found Subsystem %s"), *OnlineSubsystem->GetSubsystemName().ToString())
			);
		}
	}
};

