#include "LayerStack.h"

namespace Douter {

	LayerStack::LayerStack()
	{
		m_Stack = std::vector<ILayer*>();
	}

	LayerStack::~LayerStack()
	{
		for (ILayer* layer : m_Stack)
		{
			layer->OnDetach();
			delete layer;
		}
	}

	void LayerStack::PushLayer(ILayer* layer)
	{
		m_Stack.push_back(layer);
		layer->OnAttach();
	}

	void LayerStack::PopLayer(ILayer* layer)
	{
		for (unsigned int i = 0; i < m_Stack.size(); i++)
		{
			if (m_Stack.at(i) == layer)
			{
				layer->OnDetach();
				m_Stack.erase(m_Stack.begin() + i);
			}
		}
	}

}