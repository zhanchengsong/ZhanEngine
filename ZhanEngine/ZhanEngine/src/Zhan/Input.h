#pragma once
#include "Zhan/KeyCodes.h"
#include "Zhan/MouseCodes.h"
namespace Zhan {
	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);
		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}