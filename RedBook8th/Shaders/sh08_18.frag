#version 330 core

in float LightIntensity;
in vec3 MCposition;

uniform sampler3D Noise;
uniform vec3 Color1; // (0.8, 0.7, 0.0)
uniform vec3 Color2; // (0.6, 0.1, 0.0)
uniform float NoiseScale; // 1.2

out vec4 FragColor;

void main()
{
	vec4 noisevec = texture(Noise, MCposition * NoiseScale);
	
	float intensity = abs(noisevec[0] - 0.25) +
		abs(noisevec[1] - 0.125) +
		abs(noisevec[2] - 0.0625) +
		abs(noisevec[3] - 0.03125);
	
	intensity = clamp(intensity * 6.0, 0.0, 1.0);
	vec3 color = mix(Color1, Color2, intensity) * LightIntensity;
	FragColor = vec4(color, 1.0);
}