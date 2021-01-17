#pragma once
#include "Buffer.h"

namespace Douter {

	class VertexArray
	{
	public:
		virtual ~VertexArray() {}

		virtual void AddVertexBuffer(VertexBuffer* vertexBuffer, BufferLayout& layout) = 0;

		virtual void const Bind() = 0;
		virtual void const Unbind() = 0;

		static VertexArray* Create();
	};

}
