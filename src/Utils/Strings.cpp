/* 
 * File:   Strings.cpp
 * Author: juan.garibotti
 * 
 * Created on 24 de febrero de 2014, 16:33
 */

#include "Strings.hpp"

namespace cstr
{
    char const k_windowTitle[] = "Labyrinth";

    char const k_posColorVertexShader[] =
        "#version 330 \n"
        "uniform mat4   mvpMatrix; \n"
        "layout( location = 0 ) in vec4 i_position; \n"
        "layout( location = 1 ) in vec4 i_color; \n"
        "smooth out vec4 o_color; \n"
        "void main( void ) \n"
        "{ \n"
        "   gl_Position = mvpMatrix * i_position; \n"
        "   o_color = vec4( i_color.rgb, 0.0 ); \n"
        "} ";

    char const k_posColorFragmentShader[] =
        "#version 330 \n"
        "smooth in vec4 o_color; \n"
        "out vec4 fragColor; \n"
        "void main(void) \n"
        "{ \n"
        "   fragColor = o_color; \n"
        "} \n";
}