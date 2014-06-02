/*
 * File:   Graphics.cpp
 * Author: juan.garibotti
 *
 * Created on 24 de febrero de 2014, 14:36
 */

#include "Graphics.hpp"

#include <cassert>
#include "../Utils/Strings.hpp"
#include "GLT/Model.hpp"
#include "Movement.hpp"

GraphicsComponent::GraphicsComponent( MovementComponent const& i_movement )
: k_movement ( i_movement )
{}

void GraphicsComponent::Initialize()
{
    // OpenGL settings
    glewInit();
    glClearColor( 0.0f, 0.5f, 1.0f, 1.0f );

    // Projection settings
    m_geometryTransform.Reset();
    m_geometryTransform.DefineOrthographicProjection( -16.0, 16.0, -10.0, 10.0, -10.0, 10.0 );

    // Load shader
    m_shader = glt::LoadShaderCode( cstr::k_posColorVertexShader, cstr::k_posColorFragmentShader );

    // Bind shader
    glUseProgram( m_shader.m_shaderID );
}

void GraphicsComponent::AddModel( ModelID const& i_modelID, glt::Model const& i_model )
{
    ModelData modelData =
    {
        i_modelID,
        0,
        GL_TRIANGLES,
        0,
        GL_UNSIGNED_INT,
        0
    };
    // Create the vertex array object
    glGenVertexArrays( 1, &modelData.m_vertexArray );
    glBindVertexArray( modelData.m_vertexArray );
    {
        // Create vertex buffer object
        GLuint vertexBuffer;
        glGenBuffers( 1, &vertexBuffer );
        // Copy data to buffer object
        glBindBuffer( GL_ARRAY_BUFFER, vertexBuffer );
        glBufferData( GL_ARRAY_BUFFER, GLsizeiptr(sizeof(glt::Vertex)*i_model.m_vertexList.size()), i_model.m_vertexList.data() , GL_STATIC_DRAW );
    }
    {
        // Enable vertex position attribute
        glEnableVertexAttribArray( glt::Vertex::Position );
        glVertexAttribPointer( glt::Vertex::Position, 3, GL_FLOAT, GL_FALSE, GLsizei( sizeof( glt::Vertex ) ), 0 );
    }
    {
        // Enable texture attribute
        glEnableVertexAttribArray( glt::Vertex::Texture );
        glVertexAttribPointer (glt::Vertex::Texture, 2, GL_FLOAT, GL_FALSE, GLsizei( sizeof( glt::Vertex ) ), (GLvoid const*)(sizeof(GLfloat)*6) );
    }
    {
        // Create index buffer object
        GLuint indexBuffer;
        glGenBuffers( 1, &indexBuffer );
        // Copy index data
        glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, indexBuffer );
        glBufferData( GL_ELEMENT_ARRAY_BUFFER, GLsizeiptr(sizeof(GLuint)*i_model.m_indexList.size()), i_model.m_indexList.data(), GL_STATIC_DRAW);
    }
    // Unbind vertex array
    glBindVertexArray(0);

    modelData.m_count = GLsizei( i_model.m_indexList.size() );

    m_models.push_back( modelData );
}

void GraphicsComponent::AddEntity( GraphicsData const& i_graphicsData )
{
    m_data.push_back( i_graphicsData );
}

void GraphicsComponent::AddElement( GraphicsData const& i_element )
{
    m_elements.push_back( i_element );
}

void GraphicsComponent::Render() const
{
    glClear( GL_COLOR_BUFFER_BIT );

    for ( auto const& entity : m_data )
    {
        // Select the vertex array to draw
        assert( entity.m_modelID > 0 );
        ModelData const& model ( m_models.at( size_t( entity.m_modelID - 1 ) ) );
        glBindVertexArray( model.m_vertexArray );
        // Set the matrix uniform for the vertex shader
        glUniformMatrix4fv( (GLint)m_shader.m_mvpLocation, 1, GL_FALSE, &m_geometryTransform.BuildMVPMatrix( entity.m_frame ).m_data[0] );
        glDrawElements( model.m_mode, model.m_count, model.m_type, model.m_indices );
    }

    for ( auto const& element : m_elements )
    {
        // Select the vertex array to draw
        assert( element.m_modelID > 0 );
        ModelData const& model ( m_models.at( size_t( element.m_modelID - 1 ) ) );
        glBindVertexArray( model.m_vertexArray );
        // Set the matrix uniform for the vertex shader
        glUniformMatrix4fv( (GLint)m_shader.m_mvpLocation, 1, GL_FALSE, &m_geometryTransform.BuildMVPMatrix( element.m_frame ).m_data[0] );
        glDrawElements( model.m_mode, 6, model.m_type, model.m_indices );
    }
}

void GraphicsComponent::Update()
{
    for ( auto & entity : m_data )
    {
        MovementData const& movementData ( k_movement.GetData( entity.m_entityID ) );
        entity.m_frame.m_position[0] = movementData.m_position[0];
        entity.m_frame.m_position[1] = movementData.m_position[1];
        entity.m_frame.m_position[2] = movementData.m_position[2];
    }
}