#version 150

uniform mat4   mvpMatrix;

layout( location = 0 ) in vec4 i_position;
layout( location = 2 ) in vec2 i_texCoord;

smooth out vec2 fragTexCoord;

void main( void )
{
    fragTexCoord = i_texCoord;
    gl_Position = mvpMatrix * i_position;
}