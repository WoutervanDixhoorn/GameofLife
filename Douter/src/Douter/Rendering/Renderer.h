#pragma once

#include "Buffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"

namespace Douter {

	class Renderer
	{
	public:
		static void Draw(VertexArray& vertexArray, IndexBuffer& indexBuffer, Shader& shader);
		static void Draw(VertexArray& vertexArray, IndexBuffer& indexBuffer, Shader& shader, Texture& texture);


	};

}