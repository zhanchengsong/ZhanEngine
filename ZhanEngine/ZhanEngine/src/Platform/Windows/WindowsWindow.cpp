#include "zhpch.h"
#include "WindowsWindow.h"
#include "Zhan/Event/ApplicationEvent.h"
#include "Zhan/Event/MouseEvent.h"
#include "Zhan/Event/WindowEvent.h"
#include "Zhan/Event/KeyEvent.h"
namespace Zhan {
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int code, const char* description)
	{
		ZH_CORE_ERROR("Error ({0}):{1}", code, description);
	}
	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		Init(props);
	}


	void WindowsWindow::Init(const WindowProps& props) {
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		m_Data.Title = props.Title;

		ZH_CORE_INFO("Creating Window {0} {1} {2}", props.Title, props.Width, props.Height);
		if (!s_GLFWInitialized) {
			int success = glfwInit();
			ZH_CORE_ASSERT(success, "Could not initialize GLFW");
			s_GLFWInitialized = true;
		}
		glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);
		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		// Init Glad
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ZH_CORE_ASSERT(status, "Failed to initialize Glad");
		// Set m_data to be carried by window 
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		// Set GLFW callbacks 
		glfwSetErrorCallback(GLFWErrorCallback);
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{		
				// data is the data we set for the event to carry 
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				
				data.Width = width;
				data.Height = height;
				WindowResizeEvent event(width, height);
				data.EventCallback(event);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.EventCallback(event);

		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action) {
					case GLFW_PRESS:
					{ KeyPressedEvent kpe(key, 0);
					data.EventCallback(kpe);
					break; }
					case GLFW_RELEASE:
					{ KeyReleasedEvent kre(key);
					data.EventCallback(kre);
					break; }
					case GLFW_REPEAT:
					{ KeyPressedEvent kpe(key, 1);
					data.EventCallback(kpe);
					break; }
				}
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action) {
					case GLFW_PRESS: {
						MouseButtonPressedEvent event(button);
						data.EventCallback(event);
						break;
					} 
					case GLFW_RELEASE: {
						MouseButtonReleasedEvent event(button);
						data.EventCallback(event);
						break;
					}
				}
		
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);	
				MouseScrollEvent event(xOffset, yOffset);
				data.EventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double x, double y) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseMovedEvent event(x, y);
				data.EventCallback(event);
		});
	}




	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(m_Window);
	}

    WindowsWindow::~WindowsWindow() {
		Shutdown();
	}

	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled) {
		if (enabled) {
			glfwSwapInterval(1);
		}
		else {
			glfwSwapInterval(0);
		}
		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const {
		return m_Data.VSync;
	}
}