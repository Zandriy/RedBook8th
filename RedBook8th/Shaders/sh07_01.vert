#version 330 core

uniform mat4 MVPMatrix; // model-view-projection transform

uniform vec4 VertexColor; // sent from the application, includes alpha
layout (location = 0) in vec4 VertexPosition; // pre-transformed position

out vec4 Color; // sent to the rasterizer for interpolation

void main(void)
{
	Color = VertexColor; //vec4(0.5, 0.3, 0.7, 1.0);

    gl_Position = MVPMatrix * VertexPosition;
}