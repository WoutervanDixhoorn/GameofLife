#include "WindowsWindow.h"

#include <iostream>

#include "Douter/Events/WindowEvent.h"
#include "Douter/Events/MouseEvent.h"

namespace Douter {


	Window* Window::Create(const WinProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WinProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::Init(const WinProps& props = WinProps())
	{
		m_Data.Width = props.m_width;
		m_Data.Height = props.m_height;
		m_Data.Title = props.m_title;

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title.c_str(), NULL, NULL);
		if (m_Window == NULL)
		{
			std::cout << "Failed to create glfw Window" << std::endl;
			glfwTerminate();
		}

		glfwMakeContextCurrent(m_Window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to init Glad" << std::endl;
		}

		glViewport(0, 0, m_Data.Width, m_Data.Height);

		glfwSetWindowUserPointer(m_Window, &m_Data);

		glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.EventCallback(WindowResizeEvent(width, height));

			glViewport(0, 0, width, height);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.EventCallback(WindowCloseEvent());
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double mouse_x, double mouse_y) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.EventCallback(MouseMoveEvent(mouse_x, mouse_y));
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS:
			{
				MousePressEvent event(button);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseReleaseEvent event(button);
				data.EventCallback(event);
				break;
			}
			}
		});
	}
}