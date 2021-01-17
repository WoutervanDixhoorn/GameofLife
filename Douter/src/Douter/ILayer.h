#pragma once

#include "Events/IEvent.h"

namespace Douter {

	class ILayer {

	public:
		virtual void OnAttach() {};
		virtual void OnDetach() {};

		virtual void OnUpdate() {};
		virtual void OnEvent(IEvent& e) {};

		virtual void OnImGuiRender() {};
	};

}