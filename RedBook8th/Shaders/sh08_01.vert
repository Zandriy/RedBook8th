#version 330 core

uniform vec3 LightPosition;
uniform vec3 LightColor;
uniform vec3 EyePosition;
uniform vec3 Specular;
uniform vec3 Ambient;

uniform float Kd;
uniform mat4 MVMatrix;
uniform mat4 MVPMatrix;
uniform mat3 NormalMatrix;

layout (location = 0) in vec4 MCVertex;
layout (location = 1) in vec3 MCNormal;
in vec2 TexCoord0;

out vec3 DiffuseColor;
out vec3 SpecularColor;
out float TexCoord;

void main()
{
	vec3 ecPosition = vec3(MVMatrix * MCVertex);
	vec3 tnorm = normalize(NormalMatrix * MCNormal);
	vec3 lightVec = normalize(LightPosition - ecPosition);
	vec3 viewVec = normalize(EyePosition - ecPosition);
	vec3 hvec = normalize(viewVec + lightVec);
	
	float spec = clamp(dot(hvec, tnorm), 0.0, 1.0);
	spec = pow(spec, 16.0);
	
	DiffuseColor = LightColor * vec3(Kd * dot(lightVec, tnorm));
	DiffuseColor = clamp(Ambient + DiffuseColor, 0.0, 1.0);
	SpecularColor = clamp((LightColor * Specular * spec), 0.0, 1.0);
	TexCoord = TexCoord0.t;
	gl_Position = MVPMatrix * MCVertex;
}