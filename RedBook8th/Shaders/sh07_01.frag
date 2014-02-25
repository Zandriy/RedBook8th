#version 330 core

in vec4 Color; // interpolated between vertices

out vec4 FragColor; // color result for this fragment

void main()
{
	FragColor = Color;
}