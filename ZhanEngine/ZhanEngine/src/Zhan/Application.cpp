#include "zhpch.h"
#include "Application.h"
#include "Log.h"
#include "GLFW/glfw3.h"

namespace Zhan {
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
	Application::Application() {
		m_Window = std::unique_ptr<Window> ( Window::Create() );
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}
	Application::~Application() {
	} 
	void Application::OnEvent(Event& event) {
		ZH_CORE_TRACE("Received events: {0}", event.ToString());
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		
	}

	void Application::Run() {
		ZH_CORE_INFO("Starting Zhan Engine");
		while (m_Running) {
			glClearColor(1, 2, 3, 4);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& event) {
		m_Running = false;
		return true;
	}
}
