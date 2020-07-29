#include "zhpch.h"
#include "Application.h"
#include "Log.h"
#include "Glad/glad.h"
#include "GLFW/glfw3.h"

namespace Zhan {
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
	Application* Application::s_Instance = nullptr;

	Application::Application() {
		ZH_CORE_ASSERT(!s_Instance, "ZhanEngine should have one application instance");
		s_Instance = this;
		m_Window = std::unique_ptr<Window> ( Window::Create() );
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}
	Application::~Application() {
	} 
	void Application::OnEvent(Event& event) {
		ZH_CORE_TRACE("Received events: {0}", event.ToString());
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); ) {
			// Send this event to all the layers 
			(*--it)->OnEvent(event);
			if (event.Handled) { // if the event is handled at a layer, stop going deep 
				break;
			}
		}
	}

	void Application::Run() {
		ZH_CORE_INFO("Starting Zhan Engine");
		while (m_Running) {
			glClearColor(1, 2, 3, 4);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack) {
				layer->OnUpdate();
			}
			m_Window->OnUpdate();
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent& event) {
		m_Running = false;
		return true;
	}
}
