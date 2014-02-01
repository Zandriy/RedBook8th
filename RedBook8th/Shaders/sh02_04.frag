/* Vertex and fragment shaders that share a block of uniforms
** named "Uniforms"
*/
#version 330 core

uniform Uniforms {
	vec3 translation;
	float scale;
	vec4 rotation;
	int enabled;
};

in vec4 fColor;
out vec4 color;

void main()
{
	color = fColor;

	if ( bool(enabled) )
		color.b = 1.0;
}