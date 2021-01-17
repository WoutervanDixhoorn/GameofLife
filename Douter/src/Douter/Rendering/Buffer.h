#pragma once
#include <vector>

//Declare gl values
#define GL_BYTE 0x1400
#define GL_INT 0x1404
#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406

namespace Douter {

	static unsigned int GetShaderTypeSize(int type)
	{
		switch (type)
		{
		case GL_BYTE:
			return 1;
		case GL_FLOAT:
		case GL_INT:
		case GL_UNSIGNED_INT:
			return 4;
		}
	}

	struct BufferElement
	{
		unsigned int location;
		unsigned int count;
		unsigned int dataType;
		unsigned char normalized;
	};

	class BufferLayout
	{
	public:
		BufferLayout() {};

		inline std::vector<BufferElement>& GetElements() { return m_Elements; }

		inline unsigned int GetStride() const { return m_Stride; }

		template<typename T>
		void Push(unsigned int location, unsigned int count)
		{
			static_assert("Type's not supported");
		}

		template<>
		void Push<float>(unsigned int location, unsigned int count)
		{
			m_Elements.push_back({ location, count, GL_FLOAT, 0 });
			m_Stride += count * sizeof(float);
		}

		template<>
		void Push<unsigned int>(unsigned int location, unsigned int count)
		{
			m_Elements.push_back({ location, count, GL_UNSIGNED_INT, 0 });
			m_Stride += count * sizeof(unsigned int);
		}

	private:
		std::vector<BufferElement> m_Elements;
		unsigned int m_Stride = 0;
	};

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {};

		virtual void const Bind() = 0;
		virtual void const Unbind() = 0;

		static VertexBuffer* Create(float* vertexData, int size);
	};

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() {};

		virtual void const Bind() = 0;
		virtual void const Unbind() = 0;

		virtual int const GetSize() = 0;

		static IndexBuffer* Create(unsigned int* indexData, int size);
	};

}