#version 330 core

uniform float Frequency; // Stripe frequency = 6
uniform vec3 Color0;
uniform vec3 Color1;

in float V; // generic varying
in float LightIntensity;

out vec4 FragColor;

void main()
{
	float sawtooth = fract(V * Frequency);
	float triangle = abs(2.0 * sawtooth - 1.0);
	float dp = length(vec2(dFdx(V), dFdy(V)));
	float edge = dp * Frequency * 2.0;
	float square = smoothstep(0.5 - edge, 0.5 + edge, triangle);
	vec3 color = mix(Color0, Color1, square);
	FragColor = vec4(color, 1.0);
	FragColor.rgb *= LightIntensity;
}