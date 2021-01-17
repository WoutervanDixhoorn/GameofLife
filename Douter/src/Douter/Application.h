#pragma once

#include <string>
#include <memory>

#include "Window.h"
#include "Douter/Events/WindowEvent.h"
#include "Douter/LayerStack.h"
#include "Douter/ImGui/ImGuiLayer.h"

#include "Douter/Rendering/Texture.h"
#include "Douter/Rendering/Shader.h"
#include "Douter/Rendering/Buffer.h"
#include "Douter/Rendering/VertexArray.h"

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
		ImGuiLayer* m_ImGuiLayer;

		std::unique_ptr<Texture> m_Texture;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<VertexArray> m_VertexArray;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
	private:
		friend int ::main(int argc, char** argv);

		static Application* s_Instance;
	};

	Application* CreateApplication();
}