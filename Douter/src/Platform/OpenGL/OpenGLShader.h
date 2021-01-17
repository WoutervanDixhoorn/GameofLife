#pragma once
#include "Douter/Rendering/Shader.h"

#include <string>

namespace Douter {

	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& vertexSource, const std::string& fragmentSource);
		virtual ~OpenGLShader();

		void const Bind() override;
		void const Unbind() override;

		void SetInt(const std::string& name, int value);

	private:
		unsigned int m_RendererID = 0;
	};

}