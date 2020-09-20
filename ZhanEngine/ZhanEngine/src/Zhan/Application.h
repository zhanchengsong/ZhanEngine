#pragma once
#include "Core.h"
#include "Window.h"
#include "Zhan/Event/WindowEvent.h"
#include "Zhan/Layer/LayerStack.h"
#include "Zhan/ImGui/ImGuiLayer.h"
namespace Zhan {
	class ZHAN_API Application
	{
	public:
		Application(); 
		virtual ~Application();
		void Run();
		void OnEvent(Event& event);
		inline static Application& GetApplication() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window;  }

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& event);
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		static Application* s_Instance;
	};
	// This method is going to be defined in the client app 
	Application* CreateApplication();
}

