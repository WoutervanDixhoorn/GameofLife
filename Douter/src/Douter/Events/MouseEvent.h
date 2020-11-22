#pragma once

#include "Douter/Events/IEvent.h"

namespace Douter {

	class MouseMoveEvent : public IEvent
	{
	public:
		MouseMoveEvent(unsigned int mouse_x, unsigned int mouse_y) :
			m_MouseX(mouse_x), m_MouseY(mouse_y)
		{
		}

		unsigned int GetX() { return m_MouseX;  }
		unsigned int GetY() { return m_MouseY;  }

		EventType getType() const override { return getStaticType(); }

		static EventType getStaticType() { return EventType::MouseMoveEvent; }

	private:
		unsigned int m_MouseX, m_MouseY;
	};

	class MousePressEvent : public IEvent
	{
	public:
		MousePressEvent(unsigned int button) :
			m_Button(button)
		{
		}

		bool GetMouseButton() { return m_Button; }

		EventType getType() const override { return getStaticType(); }
		static EventType getStaticType() { return EventType::MousePressEvent; }

	private:
		unsigned int m_Button;
	};

	class MouseReleaseEvent : public IEvent
	{
	public:
		MouseReleaseEvent(unsigned int button) :
			m_Button(button)
		{
		}

		bool GetMouseButton() { return m_Button; }

		EventType getType() const override { return getStaticType(); }
		static EventType getStaticType() { return EventType::MouseReleaseEvent; }

	private:
		unsigned int m_Button;
	};

}