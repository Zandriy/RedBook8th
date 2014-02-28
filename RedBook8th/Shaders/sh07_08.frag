#version 330 core

uniform vec3 Ambient; // sets lighting level, same across many vertices
uniform vec3 LightColor;
uniform float Shininess; // exponent for sharping highlights
uniform float Strength; // extra factor to adjust shininess

in vec4 Color;
in vec3 Normal; // surface normal, interpolated between vertices

in vec3 LightDirection;
in vec3 HalfVector;
in float Attenuation;

out vec4 FragColor;

void main()
{
	float diffuse = max(0.0, dot(Normal, LightDirection));
	float specular = max(0.0, dot(Normal, HalfVector));

	if (diffuse == 0.0)
		specular = 0.0;
	else
		specular = pow(specular, Shininess) * Strength;

	vec3 scatteredLight = Ambient + LightColor * diffuse * Attenuation;
	vec3 reflectedLight = LightColor * specular * Attenuation;
	vec3 rgb = min(Color.rgb * scatteredLight + reflectedLight, vec3(1.0));
	
	FragColor = vec4(rgb, Color.a);
}