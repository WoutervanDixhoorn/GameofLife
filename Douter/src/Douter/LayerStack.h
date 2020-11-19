#pragma once
#include <vector>

#include "ILayer.h"

namespace Douter {

	class LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(ILayer* layer);
		void PopLayer(ILayer* layer);

		std::vector<ILayer*>::iterator begin() { return m_Stack.begin(); }
		std::vector<ILayer*>::iterator end() { return m_Stack.end();  }
		std::vector<ILayer*>::reverse_iterator rbegin() { return m_Stack.rbegin(); }
		std::vector<ILayer*>::reverse_iterator rend() { return m_Stack.rend(); }

		std::vector<ILayer*>::const_iterator begin() const { return m_Stack.begin(); }
		std::vector<ILayer*>::const_iterator end() const { return m_Stack.end(); }
		std::vector<ILayer*>::const_reverse_iterator rbegin() const { return m_Stack.rbegin(); }
		std::vector<ILayer*>::const_reverse_iterator rend() const { return m_Stack.rend(); }
	private:
		std::vector<ILayer*> m_Stack;
	};

}

