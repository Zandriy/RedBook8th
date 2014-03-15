#version 330 core

uniform mat4 MVPMatrix; // model-view-projection transform

uniform vec4 VertexColor; // sent from the application, includes alpha

layout (location = 0) in vec4 VertexPosition; // pre-transformed position
layout (location = 1) in vec3 VertexNormal; // we now need a surface normal
in vec2 TexCoord0;

out vec4 Color; // sent to the rasterizer for interpolation
out vec3 Normal;
out vec2 TexCoord;

void main(void)
{
	Color = VertexColor; 
	Normal = VertexNormal;
	TexCoord = TexCoord0.st;

    gl_Position = MVPMatrix * VertexPosition;
}