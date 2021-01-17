#include "OpenGLTexture.h"

#include <iostream>
#include "glad/glad.h"
#include "stb_image.h"

namespace Douter {

	Texture* Texture::Create(std::string path)
	{
		return new OpenGLTexture(path);
	}

	OpenGLTexture::OpenGLTexture(std::string path)
	{
		glGenTextures(1, &m_RendererID);
		Bind();

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_set_flip_vertically_on_load(1);

		m_ImageData = stbi_load(path.c_str(), &m_Width, &m_Height, &m_Channels, 4);

		if (m_ImageData) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_ImageData);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			std::cout << "failed to load texture" << std::endl;
		}

		Unbind();

		stbi_image_free(m_ImageData);
	}

	OpenGLTexture::~OpenGLTexture()
	{
		glDeleteTextures(1, &m_RendererID);
	}

	void const OpenGLTexture::Bind()
	{
		glActiveTexture(GL_TEXTURE0); //TODO: Make multiple slots work, only a single texture is supported now
		glBindTexture(GL_TEXTURE_2D, m_RendererID);
	}

	void const OpenGLTexture::Unbind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}