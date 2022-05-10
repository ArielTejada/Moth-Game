#version 330 core
out vec4 fragColor

in vec2 TexturePoints;

uniform sampler2D picture;

void main ()
{
	fragColor = texture(picture, TexturePoints);
}