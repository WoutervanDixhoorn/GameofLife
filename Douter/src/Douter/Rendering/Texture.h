#pragma once
#include <string>

namespace Douter {

	class Texture
	{
	public:
		virtual ~Texture() {};

		virtual void const Bind() = 0;
		virtual void const Unbind() = 0;

		static Texture* Create(std::string path);
	};

}