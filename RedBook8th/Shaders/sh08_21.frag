#version 330 core

uniform sampler3D Noise;
uniform vec3 LightWood;
uniform vec3 DarkWood;
uniform float RingFreq;
uniform float LightGrains;
uniform float DarkGrains;
uniform float GrainThreshold;
uniform vec3 NoiseScale;
uniform float Noisiness;
uniform float GrainScale;

in float LightIntensity;
in vec3 MCposition;

out vec4 FragColor;

void main()
{
	vec3 noisevec = vec3(texture(Noise, MCposition * NoiseScale) *
		Noisiness);
	vec3 location = MCposition + noisevec;
	float dist = sqrt(location.x * location.x + location.z * location.z);
	dist *= RingFreq;
	float r = fract(dist + noisevec[0] + noisevec[1] + noisevec[2])
		* 2.0;
	if (r > 1.0)
		r = 2.0 - r;
	vec3 color = mix(LightWood, DarkWood, r);
	r = fract((MCposition.x + MCposition.z) * GrainScale + 0.5);
	noisevec[2] *= r;
	if (r < GrainThreshold)
		color += LightWood * LightGrains * noisevec[2];
	else
		color -= LightWood * DarkGrains * noisevec[2];
	color *= LightIntensity;
	FragColor = vec4(color, 1.0);
}