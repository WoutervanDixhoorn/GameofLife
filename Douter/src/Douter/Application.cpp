#include "Application.h"

#include <iostream>

#include "Douter/Events/WindowEvent.h"
#include "glad/glad.h"
#include <Platform/Windows/WindowsWindow.h>

namespace Douter {

	Application* Application::s_Instance = nullptr;

	Application::Application(const std::string& name)
	{
		s_Instance = this;

		m_Window = Window::Create(WinProps(name));
		m_Window->SetEventCallbackFunction(std::bind(&Application::OnEvent, this, std::placeholders::_1));

		m_Layers = new LayerStack();

		m_Running = true;
	}

	Application::~Application()
	{
	}

	void Application::PushLayer(ILayer* layer)
	{
		m_Layers->PushLayer(layer);
	}

	void Application::PopLayer(ILayer* layer)
	{
		m_Layers->PopLayer(layer);
	}

	bool Application::OnEvent(IEvent& e)
	{
		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));

		for (unsigned int i = 0; i < m_Layers->size(); i++)
		{
			if(!e.m_Handled)
				m_Layers->at(i)->OnEvent(e);
		}

		return true;
	} 

	void Application::run()
	{
		while (m_Running)
		{
			glClear(GL_COLOR_BUFFER_BIT);

			for (unsigned int i = 0; i < m_Layers->size(); i++)
			{
				m_Layers->at(i)->OnUpdate();
			}

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}