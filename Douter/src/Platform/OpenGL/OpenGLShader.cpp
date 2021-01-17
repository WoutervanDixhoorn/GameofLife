#include "OpenGLShader.h"

#include <iostream>
#include <fstream>
#include <vector>
#include "glad/glad.h"

namespace Douter {

	Shader* Shader::Create(const std::string& vertexSource, const std::string& fragmentSource)
	{
		return new OpenGLShader(vertexSource, fragmentSource);
	}

	Shader* Shader::Create(const std::string& path)
	{
		std::ifstream fileReader(path);

		//0. VertexSource
		//1. FragmentSource
		char state = -1;

		std::string line;
		std::string vertexSource = "";
		std::string fragmentSource = "";
		
		if (fileReader.is_open())
		{
			while (std::getline(fileReader, line))
			{
				if (line.find("#shader") != std::string::npos)
				{
					if (line.find("vertex") != std::string::npos) state = 0;
					if (line.find("fragment") != std::string::npos) state = 1;
					continue;
				}

				if (!state)
				{
					vertexSource.append(line + "\n");
				}
				else {
					fragmentSource.append(line + "\n");
				}
			}
		}

		fileReader.close();

		return new OpenGLShader(vertexSource, fragmentSource);
	}

	OpenGLShader::OpenGLShader(const std::string& vertexSource, const std::string& fragmentSource)
	{
		//Straight from Khronos Wiki

		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

		const char* source = (const char*)vertexSource.c_str();
		glShaderSource(vertexShader, 1, &source, 0);

		glCompileShader(vertexShader);

		int isCompiled = 0;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			int maxLength = 0;
			glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<char> infoLog(maxLength);
			glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

			glDeleteShader(vertexShader);
			return;
		}

		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		source = (const char*)fragmentSource.c_str();
		glShaderSource(fragmentShader, 1, &source, 0);

		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			int maxLength = 0;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<char> infoLog(maxLength);
			glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

			glDeleteShader(fragmentShader);
			glDeleteShader(vertexShader);
			return;
		}

		m_RendererID = glCreateProgram();

		glAttachShader(m_RendererID, vertexShader);
		glAttachShader(m_RendererID, fragmentShader);

		glLinkProgram(m_RendererID);

		int isLinked = 0;
		glGetProgramiv(m_RendererID, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			int maxLength = 0;
			glGetProgramiv(m_RendererID, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<char> infoLog(maxLength);
			glGetProgramInfoLog(m_RendererID, maxLength, &maxLength, &infoLog[0]);
			glDeleteProgram(m_RendererID);
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			return;
		}

		glDetachShader(m_RendererID, vertexShader);
		glDetachShader(m_RendererID, fragmentShader);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_RendererID);
	}

	void const OpenGLShader::Bind()
	{
		glUseProgram(m_RendererID);
	}

	void const OpenGLShader::Unbind()
	{
		glUseProgram(0);
	}

	void OpenGLShader::SetInt(const std::string& name, int value)
	{
		int location = glGetUniformLocation(m_RendererID, name.c_str()); //TODO: Make some kind of system that save the location in a hashmap
		glUniform1i(location, value);
	}
}