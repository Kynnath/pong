#version 150

uniform sampler2D colorMap;

in vec2 fragTexCoord;
out vec4 fragColor;

void main(void)
{
   fragColor = vec4( 1.0,1.0,1.0,1.0 ) * texture( colorMap, fragTexCoord ).x;
}