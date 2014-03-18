#version 330 core

uniform sampler3D Noise;
uniform vec3 SkyColor; // (0.0, 0.0, 0.8)
uniform vec3 CloudColor; // (0.8, 0.8, 0.8)

in float LightIntensity;
in vec3 MCposition;

out vec4 FragColor;

void main()
{
	vec4 noisevec = texture(Noise, MCposition);

	float intensity = (noisevec[0] + noisevec[1] +
		noisevec[2] + noisevec[3] + 0.03125) * 1.5;

	vec3 color = mix(SkyColor, CloudColor, intensity) *
		LightIntensity;
		
	FragColor = vec4(color, 1.0);
}