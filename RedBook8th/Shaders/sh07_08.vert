#version 330 core

uniform mat4 MVPMatrix; // model-view-projection transform
uniform mat4 MVMatrix; // now need the transform, minus perspective
uniform mat3 NormalMatrix; // to transform normals, pre-perspective

uniform vec4 VertexColor; // sent from the application, includes alpha
layout (location = 0) in vec4 VertexPosition; // pre-transformed position
layout (location = 1) in vec3 VertexNormal; // we now need a surface normal

uniform vec3 LightPosition; // location of the light, eye space

uniform vec3 EyeDirection;
uniform float ConstantAttenuation; // Attenuation coefficients
uniform float LinearAttenuation;
uniform float QuadraticAttenuation;

out vec4 Color; // sent to the rasterizer for interpolation
out vec3 Normal; // interpolate the normalized surface normal

out vec3 LightDirection;
out vec3 HalfVector;
out float Attenuation;

void main(void)
{
	Color = VertexColor; 

	// transform the normal, without perspective, and normalize it
	Normal = normalize(NormalMatrix * VertexNormal);

	// find the direction and distance of the light,
	// which changes fragment to fragment for a local light
	LightDirection = LightPosition - vec3(MVMatrix * VertexPosition);
	float lightDistance = length(LightDirection);
	
	// normalize the light direction vector, so
	// that a dot products give cosines
	LightDirection = LightDirection / lightDistance;
	
	// model how much light is available for this fragment
	Attenuation = 1.0 /
			(ConstantAttenuation +
			LinearAttenuation * lightDistance +
			QuadraticAttenuation * lightDistance * lightDistance);
			
	// the direction of maximum highlight also changes per fragment
	HalfVector = normalize(LightDirection + EyeDirection);

    gl_Position = MVPMatrix * VertexPosition;
}