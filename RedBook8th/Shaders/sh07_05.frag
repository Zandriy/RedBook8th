#version 330 core

uniform vec3 Ambient; // sets lighting level, same across many vertices
uniform vec3 LightColor;
uniform vec3 LightPosition; // location of the light, eye space
uniform float Shininess; // exponent for sharping highlights
uniform float Strength; // extra factor to adjust shininess

uniform vec3 EyeDirection;
uniform float ConstantAttenuation; // attenuation coefficients
uniform float LinearAttenuation;
uniform float QuadraticAttenuation;

uniform vec3 ConeDirection; // adding spotlight attributes
uniform float SpotCosCutoff; // how wide the spot is, as a cosine
uniform float SpotExponent; // control light fall-off in the spot

in vec4 Color;
in vec3 Normal; // surface normal, interpolated between vertices
in vec4 Position;

out vec4 FragColor;

void main()
{
	// find the direction and distance of the light,
	// which changes fragment to fragment for a local light
	vec3 lightDirection = LightPosition - vec3(Position);
	float lightDistance = length(lightDirection);
	
	// normalize the light direction vector, so
	// that a dot products give cosines
	lightDirection = lightDirection / lightDistance;
	
	// model how much light is available for this fragment
	float attenuation = 1.0 /
			(ConstantAttenuation +
			LinearAttenuation * lightDistance +
			QuadraticAttenuation * lightDistance * lightDistance);
	
	// how close are we to being in the spot?
	float spotCos = dot(lightDirection, -ConeDirection);
	// attenuate more, based on spot-relative position
	if (spotCos < SpotCosCutoff)
		attenuation = 0.0;
	else
		attenuation *= pow(spotCos, SpotExponent);

	// the direction of maximum highlight also changes per fragment
	vec3 halfVector = normalize(lightDirection + EyeDirection);

	float diffuse = max(0.0, dot(Normal, lightDirection));
	float specular = max(0.0, dot(Normal, halfVector));

	if (diffuse == 0.0)
		specular = 0.0;
	else
		specular = pow(specular, Shininess) * Strength;

	vec3 scatteredLight = Ambient + LightColor * diffuse * attenuation;
	vec3 reflectedLight = LightColor * specular * attenuation;
	vec3 rgb = min(Color.rgb * scatteredLight + reflectedLight, vec3(1.0));
	
	FragColor = vec4(rgb, Color.a);
}