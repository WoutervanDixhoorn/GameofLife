#pragma once

#include "Douter/Window.h"
#include "Douter/Rendering/GraphicsContext.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Douter {

	class WindowsWindow : public Window
	{

	public:
		WindowsWindow(const WinProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		unsigned int GetWidth() const override { return m_Data.Width; }
		unsigned int GetHeight() const override { return m_Data.Height; }

		void* GetNativeWindow() override { return m_Window; }

		void SetEventCallbackFunction(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; };
	private:
		virtual void Init(const WinProps& props);
	private:
		GLFWwindow* m_Window;	
		GraphicsContext* m_Context;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};

}