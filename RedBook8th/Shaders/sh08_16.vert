#version 330 core

uniform mat4 MVMatrix;
uniform mat4 MVPMatrix;
uniform mat3 NormalMatrix;

uniform vec3 LightPos;
uniform float Scale;

layout (location = 0) in vec4 MCVertex;
layout (location = 1) in vec3 MCNormal;
in vec2 TexCoord0;

in vec4 MCvertex;
in vec3 MCnormal;

out float LightIntensity;
out vec3 MCposition;

void main()
{
	vec3 ECposition = vec3(MVMatrix * MCVertex);
	MCposition = vec3(MCVertex) * Scale;
	vec3 tnorm = normalize(vec3(NormalMatrix * MCNormal));
	LightIntensity = dot(normalize(LightPos - ECposition), tnorm);
	LightIntensity *= 1.5;
	gl_Position = MVPMatrix * MCVertex;
}