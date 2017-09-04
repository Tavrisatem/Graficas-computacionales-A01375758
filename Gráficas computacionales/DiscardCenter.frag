#version 330

in vec4 gl_FragCoord;
in vec3 InterpolatedColor;

out vec4 FragColor;

void main()
{
	vec2 pixelPositionInWindow = gl_FragCoord.xy;

	if(sqrt(pow(pixelPositionInWindow.x-200,2)+pow(pixelPositionInWindow.y-200,2))<=100)
	{
		discard;
	}
	
	FragColor = vec4(InterpolatedColor, 1.0f);
}