#include "TestLayer.h"

#include <iostream>

#include "Douter.h"
#include "ImGui/imgui.h"

void TestLayer::OnAttach()
{
	m_Texture.reset(Douter::Texture::Create("res/textures/wall.jpg"));

	m_VertexArray.reset(Douter::VertexArray::Create());

	float vertices[4 * 4] = {
		//Vertices     Texture coords
		 -0.5f, -0.5f, 1.0f, 1.0f,
		  0.5f, -0.5f, 1.0f, 0.0f,
		  0.5f,  0.5f, 0.0f, 0.0f,
		 -0.5f,  0.5f, 0.0f, 1.0f
	};

	m_VertexBuffer.reset(Douter::VertexBuffer::Create(vertices, sizeof(vertices)));

	Douter::BufferLayout layout;
	layout.Push<float>(0, 2);
	layout.Push<float>(1, 2);
	m_VertexArray->AddVertexBuffer(m_VertexBuffer.get(), layout); //TODO: Replace raw pointers with shared_ptr

	unsigned int indices[6] = { 2, 3, 0, 1, 2, 0 };
	m_IndexBuffer.reset(Douter::IndexBuffer::Create(indices, sizeof(indices)));

	m_Shader.reset(Douter::Shader::Create("res/shaders/basic.shader"));
}

void TestLayer::OnDetach()
{
}

void TestLayer::OnUpdate()
{
	m_Shader->SetInt("ourTexture", 0);

	Douter::Renderer::Draw(*m_VertexArray, *m_IndexBuffer, *m_Shader, *m_Texture);
}

void TestLayer::OnImGuiRender()
{
}

void TestLayer::OnEvent(Douter::IEvent& e)
{
}
