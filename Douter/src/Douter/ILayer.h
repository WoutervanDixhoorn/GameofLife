#pragma once

#include "Events/IEvent.h"

namespace Douter {

	class ILayer {

	public:
		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;

		virtual void OnUpdate() = 0;
		virtual bool OnEvent(IEvent& e) = 0;
	};

}