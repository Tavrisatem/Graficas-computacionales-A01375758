#version 330

in vec4 gl_FragCoord;
in vec3 InterpolatedColor;

out vec4 FragColor;

uniform vec2 Resolution;

void main()
{
	//vec2 resolution = vec2(400.0f, 400.0f);
	vec2 pixelPositionInWindow = gl_FragCoord.xy / Resolution;
	vec2 q = pixelPositionInWindow - vec2(0.5f, 0.5f);
	if(length(q) <= 0.25f)
		discard;
	
	FragColor = vec4(InterpolatedColor, 1.0f);
}


//if(sqrt(pow(pixelPositionInWindow.x-200,2)+pow(pixelPositionInWindow.y-200,2))<=100)
//{
//discard;
//}