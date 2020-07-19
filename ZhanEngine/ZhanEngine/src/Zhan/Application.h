#pragma once
#include "Core.h"
#include "Window.h"
namespace Zhan {
	class ZHAN_API Application
	{
	public:
		Application(); 
		virtual ~Application();
		void Run();
		void OnEvent(Event& event);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	// This method is going to be defined in the client app 
	Application* CreateApplication();
}

