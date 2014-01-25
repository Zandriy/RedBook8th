#version 430 core

layout(location = 0) in vec4 vPosition;
layout (location = 1) in vec3 vColor;

out vec4 fColor;

void
main()
{
	fColor = vec4(vColor, 1.0);
	gl_Position = vPosition;
}