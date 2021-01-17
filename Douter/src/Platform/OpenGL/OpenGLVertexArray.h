#pragma once
#include "Douter/Rendering/VertexArray.h"

#include <vector>

namespace Douter {

	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		void AddVertexBuffer(VertexBuffer* vertexBuffer, BufferLayout& layout) override;

		void const Bind() override;
		void const Unbind() override;

	private:
		unsigned int m_RendererId;

		std::vector<VertexBuffer*> m_VertexBuffers;
	};

}