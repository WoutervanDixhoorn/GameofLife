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

		ILayer* at(unsigned int index) { return m_Stack.at(index); }
		int size() { return m_Stack.size(); }

		std::vector<ILayer*>::iterator begin() { return m_Stack.begin(); }
		std::vector<ILayer*>::iterator end() { return m_Stack.end();  }
		std::vector<ILayer*>::reverse_iterator rbegin() { return m_Stack.rbegin(); }
		std::vector<ILayer*>::reverse_iterator rend() { return m_Stack.rend(); }
	private:
		std::vector<ILayer*> m_Stack;
	};

}

