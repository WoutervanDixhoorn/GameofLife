#pragma once

#include <string>

namespace Douter {

	class Shader
	{
	public:
		virtual ~Shader() {};

		virtual void const Bind() = 0;
		virtual void const Unbind() = 0;

		virtual void SetInt(const std::string& name, int value) = 0;

		static Shader* Create(const std::string& vertexSource, const std::string& fragmentSource);
		static Shader* Create(const std::string& path);
	};

}