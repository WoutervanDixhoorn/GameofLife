#pragma once

#include <string>

#include "Window.h"

int main(int argc, char** argv);

namespace Douter {

	class Application
	{

	public:
		Application(const std::string& name = "Douter Engine");
		virtual ~Application();

		void OnEvent(IEvent& event);

		void OnWindowClose();

		void run();
	private:
		bool m_Running = false;
		Window* m_Window;

	private:
		friend int ::main(int argc, char** argv);
	};

	Application* CreateApplication();
}