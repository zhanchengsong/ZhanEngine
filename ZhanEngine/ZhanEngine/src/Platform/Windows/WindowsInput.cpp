#include "zhpch.h"
#include "Zhan/Input.h"
#include <GLFW/glfw3.h>
#include "Zhan/Application.h"
namespace Zhan {
	bool Input::IsKeyPressed(KeyCode key){
		// For windows we assume GLFW window 
		auto window = static_cast<GLFWwindow*>(Application::GetApplication().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, static_cast<int32_t>(key));
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Input::IsMouseButtonPressed(MouseCode button)
	{
		auto window = static_cast<GLFWwindow*>(Application::GetApplication().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));
		return false;
	}

	std::pair<float, float> Input::GetMousePosition()
	{	
		auto window = static_cast<GLFWwindow*>(Application::GetApplication().GetWindow().GetNativeWindow());


		return std::pair<float, float>();
	}

	float Input::GetMouseX()
	{
		return 0.0f;
	}

	float Input::GetMouseY()
	{
		return 0.0f;
	}

	
}
