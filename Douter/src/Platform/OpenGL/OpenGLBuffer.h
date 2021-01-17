#pragma once
#include "Douter/Rendering/Buffer.h"

namespace Douter {

	class OpenGlVertexBuffer : public VertexBuffer
	{
	public:
		OpenGlVertexBuffer(float* vertexData, int size);
		virtual ~OpenGlVertexBuffer();

		void const Bind() override;
		void const Unbind() override;

	private:
		unsigned int m_RendererId;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(unsigned int* indexData, int size);
		virtual ~OpenGLIndexBuffer();

		void const Bind() override;
		void const Unbind() override;

		int const GetSize() override;

	private:
		unsigned int m_RendererId;
		int m_Size;
	};
}