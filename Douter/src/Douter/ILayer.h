#pragma once

namespace Douter {

	class ILayer {

	public:
		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;

		virtual void OnUpdate() = 0;
		virtual void OnEvent(IEvent& event) = 0;
	};

}