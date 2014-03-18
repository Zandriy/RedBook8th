#version 330 core

uniform sampler3D Noise;
uniform vec3 MarbleColor;
uniform vec3 VeinColor;

in float LightIntensity;
in vec3 MCposition;

out vec4 FragColor;

void main()
{
	vec4 noisevec = texture(Noise, MCposition);
	float intensity = abs(noisevec[0] - 0.25) +
		abs(noisevec[1] - 0.125) +
		abs(noisevec[2] - 0.0625) +
		abs(noisevec[3] - 0.03125);
	float sineval = sin(MCposition.y * 6.0 + intensity * 12.0)
		* 0.5 + 0.5;
	vec3 color = mix(VeinColor, MarbleColor, sineval)
		* LightIntensity;
	FragColor = vec4(color, 1.0);
}