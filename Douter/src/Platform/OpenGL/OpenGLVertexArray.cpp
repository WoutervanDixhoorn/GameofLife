#include "OpenGLVertexArray.h"

#include "glad/glad.h"

namespace Douter
{
	VertexArray* VertexArray::Create()
	{
		return new OpenGLVertexArray();
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererId);
		Bind();
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{

	}

	void OpenGLVertexArray::AddVertexBuffer(VertexBuffer* vertexBuffer, BufferLayout& layout)
	{
		m_VertexBuffers.push_back(vertexBuffer);
		
		static unsigned int offset = 0;
		for (BufferElement e : layout.GetElements()) {
			glEnableVertexAttribArray(e.location);
			glVertexAttribPointer(e.location, e.count, e.dataType, e.normalized, layout.GetStride(), (void*)offset);
			offset += GetShaderTypeSize(e.dataType) * e.count;
		}
	}

	void const OpenGLVertexArray::Bind()
	{
		glBindVertexArray(m_RendererId);
	}

	void const OpenGLVertexArray::Unbind()
	{
		glBindVertexArray(0);
	}
}