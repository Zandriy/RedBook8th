#version 330 core

uniform vec3 Ambient; // sets lighting level, same across many vertices
uniform vec3 LightColor;
uniform vec3 LightDirection; // direction toward the light
uniform vec3 HalfVector; // surface orientation for shiniest spots
uniform float Shininess; // exponent for sharping highlights
uniform float Strength; // extra factor to adjust shininess

in vec4 Color;
in vec3 Normal; // surface normal, interpolated between vertices

out vec4 FragColor;

void main()
{
	// compute cosine of the directions, using dot products,
	// to see how much light would be reflected
	float diffuse = max(0.0, dot(Normal, LightDirection));
	float specular = max(0.0, dot(Normal, HalfVector));
	
	// surfaces facing away from the light (negative dot products)
	// won’t be lit by the directional light
	if (diffuse == 0.0)
		specular = 0.0;
	else
		specular = pow(specular, Shininess); // sharpen the highlight
	
	vec3 scatteredLight = Ambient + LightColor * diffuse;
	vec3 reflectedLight = LightColor * specular * Strength;
	
	// don’t modulate the underlying color with reflected light,
	// only with scattered light
	vec3 rgb = min(Color.rgb * scatteredLight + reflectedLight, vec3(1.0));
	FragColor = vec4(rgb, Color.a);
}