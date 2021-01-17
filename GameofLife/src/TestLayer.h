#pragma once

#include "Douter.h"

class TestLayer : public Douter::ILayer
{
public:
	void OnAttach() override;
	void OnDetach() override;

	void OnUpdate() override;
	void OnEvent(Douter::IEvent& e) override;

	void OnImGuiRender() override;

private:
	std::unique_ptr<Douter::Texture> m_Texture;
	std::unique_ptr<Douter::Shader> m_Shader;
	std::unique_ptr<Douter::VertexBuffer> m_VertexBuffer;
	std::unique_ptr<Douter::VertexArray> m_VertexArray;
	std::unique_ptr<Douter::IndexBuffer> m_IndexBuffer;
};

