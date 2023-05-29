#pragma once

#include <CoreMinimal.h>
#include <Engine.h>
#include <sstream>

namespace util
{
	template<typename T>
	std::string to_str(const T& value) {
		std::ostringstream tmp_str;
		tmp_str << value;
		return tmp_str.str();
	}

	template<typename T, typename ... Args >
	std::string to_str(const T& value, const Args& ... args) {
		return to_str(value) + to_str(args...);
	}
}

class GEngineInterface
{
public:
	/// <summary>
	/// Used to Wrap the GEngine Log Message function, was too much clutter for me
	/// </summary>
	/// <param name="color">The color of the log message</param>
	/// <param name="log">The log message</param>
	static void AddOnScreenDebugMessage(const FColor& color, const std::string& log)
	{
		if (GEngine != nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, color, FString(log.c_str()));
		}
	}
};