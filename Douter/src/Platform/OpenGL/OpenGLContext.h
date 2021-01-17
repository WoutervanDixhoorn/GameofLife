#pragma once

#include "Douter/Rendering/GraphicsContext.h"

#include "GLFW/glfw3.h"

namespace Douter{

class OpenGLContext : public GraphicsContext
{
public:
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle);

	void Init() override;
	void SwapBuffers() override;

private:
	GLFWwindow* m_WindowHandle;
};

}
