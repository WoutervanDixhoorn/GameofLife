#pragma once

#include "IEvent.h"

namespace Douter {

	class WindowResizeEvent : public IEvent
	{
	public:
		WindowResizeEvent(unsigned int Width, unsigned int Height) : m_Width(Width), m_Height(Height) {}

		unsigned int GetWidth() { return m_Width; }
		unsigned int GetHeight() { return m_Height; }

		EventType getType() const override { return getStaticType(); }

		static EventType getStaticType() { return EventType::WindowResizeEvent; }

	private:
		unsigned int m_Width;
		unsigned int m_Height;
	};

	class WindowCloseEvent : public IEvent
	{
	public:
		EventType getType() const override { return getStaticType(); }

		static EventType getStaticType() { return EventType::WindowCloseEvent; }
	};

}