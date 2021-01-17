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
		void OnDetach() override;

		void OnUpdate() override;

		void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0;
	};

}