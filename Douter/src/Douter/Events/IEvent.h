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

		template<typename t, typename f>
		void Dispatch(const f& Fn)
		{	
			if (m_Event.getType() == t::getStaticType())
			{
				Fn();
			}
		}

	private:
		IEvent& m_Event;
	};
}