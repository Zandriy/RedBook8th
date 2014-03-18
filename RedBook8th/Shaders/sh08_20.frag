#version 330 core

uniform sampler3D Noise;
uniform float NoiseScale;

in float LightIntensity;
in vec3 MCposition;

out vec4 FragColor;

void main()
{
	vec4 noisevec = texture(Noise, NoiseScale * MCposition);
	float intensity = min(1.0, noisevec[3] * 18.0);
	vec3 color = vec3(intensity * LightIntensity);
	FragColor = vec4(color, 1.0);
}