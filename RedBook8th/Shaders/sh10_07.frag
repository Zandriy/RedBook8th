#version 330 core

uniform vec2 Scale;
uniform vec2 Threshold;

in vec2 TexCoord;
in vec4 Color;

out vec4 FragColor;
in vec3 Normal;

void main()
{
	float ss = fract(TexCoord.s * Scale.s);
	float tt = fract(TexCoord.t * Scale.t);

	if ((ss > Threshold.s) && (tt > Threshold.t))
		discard;

	vec3 LightDirection = vec3(0.0f, 0.0f, 1.0f);

	float d = max(0.0, dot(Normal, LightDirection));

	FragColor = Color * d;
}