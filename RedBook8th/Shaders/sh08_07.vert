#version 330 core

uniform vec4 MCBallCenter;
uniform mat4 MVMatrix;
uniform mat4 MVPMatrix;
uniform mat3 NormalMatrix;

layout (location = 0) in vec4 MCVertex;

out vec3 OCPosition;
out vec4 ECPosition;

flat out vec4 ECBallCenter;

void main (void)
{
	OCPosition = MCVertex.xyz;
	ECPosition = MVMatrix * MCVertex;
	ECBallCenter = MVMatrix * MCBallCenter;
	gl_Position = MVPMatrix * MCVertex;
}