#include "Application.h"

#include <iostream>

#include "Douter/Events/WindowEvent.h"

namespace Douter {

	Application::Application(const std::string& name)
	{
		m_Window = Window::Create(WinProps(name));
		m_Window->SetEventCallbackFunction(std::bind(&Application::OnEvent, this, std::placeholders::_1));

		m_Running = true;
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(IEvent& event)
	{
		
		EventDispatcher dispatcher(event);

		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this));

	} 

	void Application::run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}

	void Application::OnWindowClose()
	{
		m_Running = false;
	}

}