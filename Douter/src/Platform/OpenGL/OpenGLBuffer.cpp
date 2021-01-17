#include "OpenGLBuffer.h"

#include "glad/glad.h"

namespace Douter {

	//VERTEX BUFFER//

	VertexBuffer* VertexBuffer::Create(float* vertexData, int size)
	{
		return new OpenGlVertexBuffer(vertexData, size);
	}

	OpenGlVertexBuffer::OpenGlVertexBuffer(float* vertexData, int size)
	{
		glCreateBuffers(1, &m_RendererId);
		Bind();
		glBufferData(GL_ARRAY_BUFFER, size, vertexData, GL_STATIC_DRAW); //TODO: STATIC_DRAW is temporary
	}

	OpenGlVertexBuffer::~OpenGlVertexBuffer()
	{

	}

	void const OpenGlVertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererId);
	}

	void const OpenGlVertexBuffer::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	//INDEX BUFFER//

	IndexBuffer* IndexBuffer::Create(unsigned int* indexData, int size)
	{
		return new OpenGLIndexBuffer(indexData, size);
	}

	OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int* indexData, int size)
	{
		glCreateBuffers(1, &m_RendererId);
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indexData, GL_STATIC_DRAW); //TODO: STATIC_DRAW is temporary
		m_Size = size;
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{

	}

	void const OpenGLIndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererId);
	}

	void const OpenGLIndexBuffer::Unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	int const OpenGLIndexBuffer::GetSize()
	{
		return m_Size;
	}
}