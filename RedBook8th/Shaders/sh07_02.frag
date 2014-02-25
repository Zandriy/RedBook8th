#version 330 core

uniform vec4 Ambient; // sets lighting level, same across many vertices

in vec4 Color;

out vec4 FragColor;

void main()
{
	vec4 scatteredLight = Ambient; // this is the only light
	// modulate surface color with light, but saturate at white
	FragColor = min(Color * scatteredLight, vec4(1.0));
}