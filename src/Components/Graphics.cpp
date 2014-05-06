/*
 * File:   Graphics.cpp
 * Author: juan.garibotti
 *
 * Created on 24 de febrero de 2014, 14:36
 */

#include "Graphics.hpp"

#include "../Utils/Strings.hpp"
#include "GLT/Model.hpp"

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

    // Load models
    glt::Model paddle( obj::Object( "resource/model/paddle.obj") );
    // Create the vertex array object
    glGenVertexArrays( 1, &vertexArrayBufferObject );
    glBindVertexArray( vertexArrayBufferObject );
    // Create vertex buffer object
    GLuint vertexBuffer;
    glGenBuffers( 1, &vertexBuffer );
    // Copy data to buffer object
    glBindBuffer( GL_ARRAY_BUFFER, vertexBuffer );
    glBufferData( GL_ARRAY_BUFFER, GLsizeiptr(sizeof(glt::Vertex)*paddle.m_vertexList.size()), paddle.m_vertexList.data() , GL_STATIC_DRAW );
    // Enable vertex position attribute
    glEnableVertexAttribArray( glt::Vertex::Position );
    glVertexAttribPointer( glt::Vertex::Position, 3, GL_FLOAT, GL_FALSE, GLsizei( sizeof( glt::Vertex ) ), 0 );
    // Create index buffer object
    GLuint indexBuffer;
    glGenBuffers( 1, &indexBuffer );
    // Copy index data
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, indexBuffer );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, GLsizeiptr(sizeof(GLuint)*paddle.m_indexList.size()), paddle.m_indexList.data(), GL_STATIC_DRAW);
    // Unbind vertex array
    glBindVertexArray(0);

    // GraphicsData
    GraphicsData paddleGraphicsData =
    {
        0,  // entity id
        { { { 0, 0, 0 } }, { { 0, 0, 1 } }, { { 0, 1, 0 } } }, // Frame
        0 // Model index
    };
    AddEntity( paddleGraphicsData );
}

void GraphicsComponent::AddModel( glt::Model const& i_model )
{
    ModelData modelData;
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
        // Create index buffer object
        GLuint indexBuffer;
        glGenBuffers( 1, &indexBuffer );
        // Copy index data
        glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, indexBuffer );
        glBufferData( GL_ELEMENT_ARRAY_BUFFER, GLsizeiptr(sizeof(GLuint)*i_model.m_indexList.size()), i_model.m_indexList.data(), GL_STATIC_DRAW);
    }
    // Unbind vertex array
    glBindVertexArray(0);

    modelData.m_mode = GL_TRIANGLES;
    modelData.m_count = GLsizei( i_model.m_indexList.size() );
    modelData.m_type = GL_UNSIGNED_INT;
    modelData.m_indices = 0;

    m_models.push_back( modelData );
}

void GraphicsComponent::AddEntity( GraphicsData const& i_graphicsData )
{
    m_data.push_back( i_graphicsData );
}

void GraphicsComponent::Render() const
{
    glClear( GL_COLOR_BUFFER_BIT );

    for ( auto const& entity : m_data )
    {
        // Select the vertex array to draw
        ModelData const& model ( m_models.at( entity.m_modelIndex ) );
        glBindVertexArray( model.m_vertexArray );
        // Set the matrix uniform for the vertex shader
        glUniformMatrix4fv( (GLint)m_shader.m_mvpLocation, 1, GL_FALSE, &m_geometryTransform.BuildMVPMatrix( entity.m_frame ).m_data[0] );
        glDrawElements( model.m_mode, model.m_count, model.m_type, model.m_indices );
    }

}

void GraphicsComponent::Update()
{}