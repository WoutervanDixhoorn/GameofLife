#pragma once


namespace Douter {

	enum class EventType {
		WindowCloseEvent,
		WindowResizeEvent,
		MouseMoveEvent,
		MousePressEvent,
		MouseReleaseEvent
	};

	class IEvent
	{
	public:
		virtual EventType getType() const = 0;

		bool m_Handled = false;
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(IEvent& event) : m_Event(event) {}

		template<typename T, typename F>
		void Dispatch(const F& func)
		{	
			if (m_Event.getType() == T::getStaticType())
			{
				m_Event.m_Handled = func(static_cast<T&>(m_Event));
			}
		}

	private:
		IEvent& m_Event;
	};
}