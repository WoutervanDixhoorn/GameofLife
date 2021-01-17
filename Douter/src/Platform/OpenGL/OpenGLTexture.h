#pragma once

#include "Douter/Rendering/Texture.h"

namespace Douter {

	class OpenGLTexture : public Texture
	{
	public:
		OpenGLTexture(std::string path);
		virtual ~OpenGLTexture();

		void const Bind() override;
		void const Unbind() override;

	private:
		unsigned int m_RendererID = 0;

		int m_Width, m_Height, m_Channels;
		unsigned char *m_ImageData;
	};

}