#version 150

uniform sampler2D alpha;

smooth in vec2 fragTexCoord;
out vec4 fragColor;

void main(void)
{
   fragColor = vec4( 1.0, 1.0, 1.0, texture( alpha, fragTexCoord ).r );
}