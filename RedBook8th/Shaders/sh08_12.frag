#version 330 core
 
uniform vec3 BrickColor, MortarColor;
uniform vec2 BrickSize;
uniform vec2 BrickPct;
uniform vec2 MortarPct;

in vec2 MCPosition;
in float LightIntensity;

out vec4 FragColor;

#define Integral(x, p, notp) ((floor(x)*(p)) + max(fract(x)-(notp), 0.0))

void main()
{
	vec2 position, fw, useBrick;
	vec3 color;	
	// Determine position within the brick pattern

	position = MCPosition / BrickSize;
	// Adjust every other row by an offset of half a brick
	if (fract(position.y * 0.5) > 0.5)
		position.x += 0.5;

	if ( MortarPct.x > 0.0 && MortarPct.y > 0.0)
	{
		// Calculate filter size
		fw = fwidth(position);
		// Perform filtering by integrating the 2D pulse made by the
		// brick pattern over the filter width and height
		useBrick = (Integral(position + fw, BrickPct, MortarPct) -
				Integral(position, BrickPct, MortarPct)) / fw;
	}
	else
	{
	 	position = fract(position);
	 	useBrick = step(position, BrickPct);
	}

	// Determine final color
	color = mix(MortarColor, BrickColor, useBrick.x * useBrick.y);
	color *= LightIntensity;
	FragColor = vec4(color, 1.0);
}
