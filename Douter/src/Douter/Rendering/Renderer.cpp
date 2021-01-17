#include "Renderer.h"

#include "memory"

#include "glad/glad.h"

namespace Douter {

	void Renderer::Draw(VertexArray& vertexArray, IndexBuffer& indexBuffer, Shader& shader)
	{
		vertexArray.Bind();
		indexBuffer.Bind();
		shader.Bind();

		glDrawElements(GL_TRIANGLE_FAN, indexBuffer.GetSize(), GL_UNSIGNED_INT, nullptr);
	}

	void Renderer::Draw(VertexArray& vertexArray, IndexBuffer& indexBuffer, Shader& shader, Texture& texture)
	{
		texture.Bind();
		vertexArray.Bind();
		indexBuffer.Bind();
		shader.Bind();

		glDrawElements(GL_TRIANGLE_FAN, indexBuffer.GetSize(), GL_UNSIGNED_INT, nullptr);
	}

}