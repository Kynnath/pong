#version 150
#extension GL_ARB_explicit_attrib_location : enable

uniform mat4   mvpMatrix;

layout( location = 0 ) in vec4 i_position;

void main( void )
{
    gl_Position = mvpMatrix * i_position;
}