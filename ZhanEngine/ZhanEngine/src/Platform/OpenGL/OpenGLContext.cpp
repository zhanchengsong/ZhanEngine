#include "zhpch.h"
#include "OpenGLContext.h"
#include <GLFW/glfw3.h>
#include <Glad/glad.h>
namespace Zhan {
    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) 
        : m_WindowHandle(windowHandle)
    {
        ZH_CORE_ASSERT(windowHandle, "Window handle is null !");
    }
    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
        // Init Glad
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        ZH_CORE_ASSERT(status, "Failed to initialize Glad");
        ZH_CORE_INFO("OpenGL Renderer: {0}, {1}", glGetString(GL_VENDOR), glGetString(GL_RENDERER));
        ZH_CORE_INFO("  Vendor: {0} ", glGetString(GL_VENDOR));
        ZH_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
        ZH_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

        
    }
    void OpenGLContext::SwapBuffers()
    {   
        glfwSwapBuffers(m_WindowHandle);
    }
}