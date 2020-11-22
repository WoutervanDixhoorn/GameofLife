#pragma once

#include <string>

#include "Window.h"
#include "Douter/Events/WindowEvent.h"
#include "Douter/LayerStack.h"


int main(int argc, char** argv);

namespace Douter {

	class Application
	{

	public:
		Application(const std::string& name = "Douter Engine");
		virtual ~Application();

		inline static Application& Get() { return *s_Instance; };
		inline Window& GetWindow() { return *m_Window;  };

		void PushLayer(ILayer* layer);
		void PopLayer(ILayer* layer);

		bool OnEvent(IEvent& e);
		bool OnWindowClose(WindowCloseEvent& e);

		void run();
	private:
		bool m_Running = false;
		Window* m_Window;

		LayerStack* m_Layers;
	private:
		friend int ::main(int argc, char** argv);

		static Application* s_Instance;
	};

	Application* CreateApplication();
}