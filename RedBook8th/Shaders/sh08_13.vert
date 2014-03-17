#version 330 core

layout (location = 0) in vec4 MCvertex;
layout (location = 1) in vec2 MCTexCoord;
layout (location = 2) in vec3 MCnormal;

uniform mat4 MVMatrix;
uniform mat4 MVPMatrix;
uniform mat3 NormalMatrix;
uniform vec3 LightPosition;

const float SpecularContribution = 0.3;
const float DiffuseContribution = 1.0 - SpecularContribution;

out vec2 TexCoord;
out float LightIntensity;

void main()
{
	vec3 ecPosition = vec3(MVMatrix * MCvertex);
	vec3 tnorm = normalize(NormalMatrix * MCnormal);
	vec3 lightVec = normalize(LightPosition - ecPosition);
	vec3 reflectVec = reflect(-lightVec, tnorm);
	vec3 viewVec = normalize(-ecPosition);
	float diffuse = max(dot(lightVec, tnorm), 0.0);
	float spec = 0.0;
	
	if (diffuse > 0.0)
	{
		spec = max(dot(reflectVec, viewVec), 0.0);
		spec = pow(spec, 16.0);
	}
	
	LightIntensity = DiffuseContribution * diffuse +
		SpecularContribution * spec;
	TexCoord = MCTexCoord.st;
	gl_Position = MVPMatrix * MCvertex;
}