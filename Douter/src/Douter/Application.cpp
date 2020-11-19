#include "Application.h"

#include <iostream>

#include "Douter/Events/WindowEvent.h"


#define HZ_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Douter {

	Application::Application(const std::string& name)
	{
		m_Window = Window::Create(WinProps(name));
		m_Window->SetEventCallbackFunction(HZ_BIND_EVENT_FN(Application::OnEvent));

		m_Running = true;
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(IEvent& e)
	{
		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));

	} 

	void Application::run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}

	void Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
	}

}