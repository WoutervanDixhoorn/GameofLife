#include "OpenGLContext.h"
#include "glad/glad.h"
#include <iostream>

#include "Douter/Window.h"

namespace Douter {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
	{
		m_WindowHandle = windowHandle;
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to init Glad" << std::endl;
		}

		std::cout << GLVersion.major << "." << GLVersion.minor << std::endl;
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}