#version 330 core

uniform mat4 MVPMatrix; // model-view-projection transform
uniform mat4 MVMatrix; // now need the transform, minus perspective
uniform mat3 NormalMatrix; // to transform normals, pre-perspective

uniform vec4 VertexColor; // sent from the application, includes alpha
layout (location = 0) in vec4 VertexPosition; // pre-transformed position
layout (location = 1) in vec3 VertexNormal; // we now need a surface normal

// uniform vec3 LightPosition; // location of the light, eye space
// 
// uniform vec3 EyeDirection;
// uniform float ConstantAttenuation; // Attenuation coefficients
// uniform float LinearAttenuation;
// uniform float QuadraticAttenuation;

out vec4 Color; // sent to the rasterizer for interpolation
out vec3 Normal; // interpolate the normalized surface normal
out vec4 Position;

// out vec3 LightDirection;
// out vec3 HalfVector;
// out float Attenuation;

void main(void)
{
	Color = VertexColor;
	Normal = normalize(NormalMatrix * VertexNormal);

	Position = MVMatrix * VertexPosition;
	gl_Position = MVPMatrix * VertexPosition;
}