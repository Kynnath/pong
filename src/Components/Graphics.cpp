/*
 * File:   Graphics.cpp
 * Author: juan.garibotti
 *
 * Created on 24 de febrero de 2014, 14:36
 */

#include "Graphics.hpp"

#include <cassert>
#include <fstream>
#include "GLT/Model.hpp"
#include "FNT/Face.hpp"
#include "TGA/tga.hpp"
#include "Movement.hpp"

GraphicsComponent::GraphicsComponent( MovementComponent const& i_movement, GameLogicComponent const& i_gameLogic )
: k_movement ( i_movement )
, k_gameLogic ( i_gameLogic )
{}

void GraphicsComponent::Initialize( GraphicsSettings const& i_settings )
{
    // OpenGL settings
    glewInit();
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Font init
    fnt::Face face { "resource/font/ocraext.ttf", 12 };

    // Load catalogs
    m_modelCatalog.LoadConfiguration( i_settings.m_modelCatalog );
    m_shaderCatalog.LoadConfiguration( i_settings.m_shaderCatalog );
    m_textureCatalog.LoadConfiguration( i_settings.m_textureCatalog );

    // Projection settings
    m_geometryTransform.Reset();
    m_geometryTransform.DefineOrthographicProjection( -16.0, 16.0, -10.0, 10.0, -10.0, 10.0 );

    // Load shaders
    {
        std::ifstream shaderFile { "resource/shader/PassThrough.vs" };
        std::string vertexShader;
        char character = static_cast<char>( shaderFile.get() );
        while ( shaderFile.good() )
        {
            vertexShader += character;
            character = static_cast<char>( shaderFile.get() );
        }
        shaderFile.close();
        shaderFile.open( "resource/shader/PassThrough.fs" );
        std::string fragmentShader;
        character = static_cast<char>( shaderFile.get() );
        while ( shaderFile.good() )
        {
            fragmentShader += character;
            character = static_cast<char>( shaderFile.get() );
        }
        m_shaders.push_back( glt::LoadShaderCode( vertexShader.c_str(), fragmentShader.c_str() ) );
        shaderFile.close();
        vertexShader.clear();
        fragmentShader.clear();
        // Function Load shader

        shaderFile.open( "resource/shader/Textured.vs" );
        character = static_cast<char>( shaderFile.get() );
        while ( shaderFile.good() )
        {
            vertexShader += character;
            character = static_cast<char>( shaderFile.get() );
        }
        shaderFile.close();
        shaderFile.open( "resource/shader/Textured.fs" );
        character = static_cast<char>( shaderFile.get() );
        while ( shaderFile.good() )
        {
            fragmentShader += character;
            character = static_cast<char>( shaderFile.get() );
        }
        m_shaders.push_back( glt::LoadShaderCode( vertexShader.c_str(), fragmentShader.c_str() ) );
        glUniform1i(glGetUniformLocation(m_shaders.back().m_shaderID, "colorMap"), 0);
    }
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
    /*{
        // Not enabled since obj files don't hold color information
        glEnableVertexAttribArray( glt::Vertex::Color );
        glVertexAttribPointer( glt::Vertex::Color, 3, GL_FLOAT, GL_FALSE, GLsizei( sizeof( glt::Vertex ) ), (GLvoid const*)(sizeof(GLfloat)*3) );
    }*/
    {
        // Enable texture attribute
        glEnableVertexAttribArray( glt::Vertex::Texture );
        glVertexAttribPointer( glt::Vertex::Texture, 2, GL_FLOAT, GL_FALSE, GLsizei( sizeof( glt::Vertex ) ), (GLvoid const*)(sizeof(GLfloat)*6) );
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

void GraphicsComponent::AddTexture( std::string const& i_texture )
{
    m_texes.push_back( glt::Texture { tga::MakeImage( "resource/texture/" + m_textureCatalog.GetStringProperty( i_texture + "::file" ) ) } );
}

void GraphicsComponent::Update()
{
    for ( auto & entity : m_data )
    {
        MovementData const& movementData ( k_movement.GetData( entity.m_id ) );
        entity.m_frame.m_position[0] = movementData.m_position[0];
        entity.m_frame.m_position[1] = movementData.m_position[1];
        entity.m_frame.m_position[2] = movementData.m_position[2];
    }

    playerScoreOffset = static_cast<size_t>(k_gameLogic.GetPlayerScore())%10 * sizeof(GL_UNSIGNED_INT) * 6;
    aiScoreOffset = static_cast<size_t>(k_gameLogic.GetAIScore())%10 * sizeof(GL_UNSIGNED_INT) * 6;
}

void GraphicsComponent::Render() const
{
    glClear( GL_COLOR_BUFFER_BIT );

    glUseProgram( m_shaders.front().m_shaderID );
    for ( auto const& entity : m_data )
    {
        // Select the vertex array to draw
        assert( entity.m_modelID > 0 );
        ModelData const& model ( m_models.at( std::size_t( entity.m_modelID - 1 ) ) );
        glBindVertexArray( model.m_vertexArray );
        // Set the matrix uniform for the vertex shader
        glUniformMatrix4fv( (GLint)m_shaders.front().m_mvpLocation, 1, GL_FALSE, &m_geometryTransform.BuildMVPMatrix( entity.m_frame ).m_data[0] );
        glDrawElements( model.m_mode, model.m_count, model.m_type, model.m_indices );
    }

    glUseProgram( m_shaders.back().m_shaderID );
    int scoreOffset { 0 };
    std::size_t const offsets[2] =
    {
        playerScoreOffset,
        aiScoreOffset
    };
    glBindTexture( GL_TEXTURE_2D, m_texes.front().Name() );
    for ( auto const& element : m_elements )
    {
        // Select the vertex array to draw
        assert( element.m_modelID > 0 );
        ModelData const& model ( m_models.at( std::size_t( element.m_modelID - 1 ) ) );
        glBindVertexArray( model.m_vertexArray );
        // Set the matrix uniform for the vertex shader
        glUniformMatrix4fv( (GLint)m_shaders.back().m_mvpLocation, 1, GL_FALSE, &m_geometryTransform.BuildMVPMatrix( element.m_frame ).m_data[0] );
        glDrawElements( model.m_mode, 6, model.m_type, reinterpret_cast<GLvoid const*>( reinterpret_cast<char const*>(model.m_indices)+offsets[scoreOffset] ) );
        ++scoreOffset;
    }
}
