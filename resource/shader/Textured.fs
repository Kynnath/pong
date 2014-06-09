#version 150

uniform sampler2D colorMap;

in vec2 fragTexCoord;
out vec4 fragColor;

void main(void)
{
   fragColor = texture( colorMap, fragTexCoord );
}