#shader vertex

#version 330 core
layout(location = 0) in vec2 a_Position;
layout(location = 1) in vec2 a_TexCoords;

out vec2 TexCoords;

void main()
{
	gl_Position = vec4(a_Position, 0.0, 1.0);
	TexCoords = a_TexCoords;
}

#shader fragment

#version 330 core
in vec2 TexCoords;

out vec4 color;

uniform sampler2D ourTexture;

void main()
{
	color = texture(ourTexture, TexCoords);
}