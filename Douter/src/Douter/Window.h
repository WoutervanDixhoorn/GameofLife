#pragma once

#include <string>
#include <functional>

#include "Events/IEvent.h"

namespace Douter {

	struct WinProps
	{
		std::string m_title;
		unsigned int m_width;
		unsigned int m_height;

		WinProps(const std::string& title = "Douter Engine", unsigned int width = 1280, unsigned int height = 720) :
			m_title(title), m_width(width), m_height(height)
		{
		}
	};

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(IEvent&)>;

		virtual ~Window() {};

		virtual void SetEventCallbackFunction(const EventCallbackFn& eventCallBackFn) = 0;

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void* GetNativeWindow() = 0;

		static Window* Create(const WinProps& props = WinProps());
	};

}