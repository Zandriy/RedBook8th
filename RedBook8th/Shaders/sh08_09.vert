#version 330 core

uniform vec3 LightPosition;

uniform mat4 MVMatrix;
uniform mat4 MVPMatrix;
uniform mat3 NormalMatrix;

layout (location = 0) in vec4 MCVertex;
layout (location = 1) in vec3 MCNormal;

//in vec3 MCTangent;
in vec2 TexCoord0;

out vec3 LightDir;
out vec3 EyeDir;
out vec2 TexCoord;

void main()
{
	vec3 MCTangent = MCNormal;
 	MCTangent.x /= 5;
 	MCTangent.y *= 2;
 	MCTangent.z /= 4;

	EyeDir = vec3(MVMatrix * MCVertex);
	TexCoord = TexCoord0.st;
	vec3 n = normalize(NormalMatrix * MCNormal);
	vec3 t = normalize(NormalMatrix * MCTangent);
	vec3 b = cross(n, t);
	vec3 v;
	v.x = dot(LightPosition, t);
	v.y = dot(LightPosition, b);
	v.z = dot(LightPosition, n);
	LightDir = normalize(v);
	v.x = dot(EyeDir, t);
	v.y = dot(EyeDir, b);
	v.z = dot(EyeDir, n);
	EyeDir = normalize(v);
	gl_Position = MVPMatrix * MCVertex;
}