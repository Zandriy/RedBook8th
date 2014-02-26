#version 330 core

uniform vec4 Ambient; // sets lighting level, same across many vertices

in vec4 Color;

out vec4 FragColor;
in vec3 Normal;

void main()
{
	//vec4 scatteredLight = Ambient; // this is the only light
	// modulate surface color with light, but saturate at white
	//FragColor = min(Color * scatteredLight, vec4(1.0));

	vec3 LightDirection = vec3(0.0f, 0.0f, 1.0f);

	float d = max(0.0, dot(Normal, LightDirection));

	FragColor = vec4(1.0, 1.0, 1.0, 1.0) * d;
}