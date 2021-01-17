#pragma once

#include "Douter/Window.h"

namespace Douter {

	class GraphicsContext
	{
	public:
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
	};

}
