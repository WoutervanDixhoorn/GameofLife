#pragma once


namespace Douter {

	enum class EventType {
		WindowCloseEvent,
		WindowResizeEvent
	};

	class IEvent
	{
	public:
		virtual EventType getType() const = 0;

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
				func(static_cast<T&>(m_Event));
			}
		}

	private:
		IEvent& m_Event;
	};
}