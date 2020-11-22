#pragma once

#include "Douter/ILayer.h"
#include <Douter/Events/MouseEvent.h>

namespace Douter {

	class ImGuiLayer : public ILayer
	{
	public:
		ImGuiLayer() : ILayer()
		{
		}

		~ImGuiLayer()
		{
		}

		void OnAttach() override;
		void OnDetach() override ;

		void OnUpdate() override;
		bool OnEvent(IEvent& e) override;

	private:
		bool OnMouseMove(MouseMoveEvent& e);
		bool OnMousePress(MousePressEvent& e);
		bool OnMouseRelease(MouseReleaseEvent& e);
	private:
		float m_Time = 0;
	};

}