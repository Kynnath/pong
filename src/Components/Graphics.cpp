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
#include "TGA/tga.hpp"
#include "TLS/Tools.hpp"
#include "Movement.hpp"
#include <iostream>
namespace
{
  constexpr auto shaderLoc = "resource/shader/";
  
  std::vector<glt::Shader> LoadShaders(cfg::Config const& i_catalog)
  {
    std::vector<glt::Shader> shaders;
    for(auto shaderName = std::begin(i_catalog); shaderName != std::end(i_catalog); ++shaderName)
    {
      std::ifstream fragmentFile { shaderLoc + shaderName->second.GetString() };
      auto const fragmentShader = tls::StringFromFile( fragmentFile );
      
      ++shaderName;
      
      std::ifstream vertexFile { shaderLoc + shaderName->second.GetString() };
      auto const vertexShader = tls::StringFromFile( vertexFile );
      
      shaders.push_back( glt::LoadShaderCode( vertexShader.c_str(), fragmentShader.c_str() ) );
    }
    return shaders;
  }
}

GraphicsComponent::GraphicsComponent( MovementComponent const& i_movement )
  : k_movement ( i_movement )
{}

void GraphicsComponent::Initialize( GraphicsSettings const& i_settings )
{
  // OpenGL settings
  glewInit();
  glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  // Load catalogs
  m_modelCatalog.LoadConfiguration( i_settings.m_modelCatalog );
  m_shaderCatalog.LoadConfiguration( i_settings.m_shaderCatalog );
  m_textureCatalog.LoadConfiguration( i_settings.m_textureCatalog );

  // Projection settings
  m_geometryTransform.Reset();
  m_geometryTransform.DefineOrthographicProjection( -16.0, 16.0, -10.0, 10.0, -1.0, 1.0 );

  m_shaders = LoadShaders(m_shaderCatalog);
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
}

void GraphicsComponent::Render() const
{
  glClear( GL_COLOR_BUFFER_BIT );

  glUseProgram( m_shaders[0].m_shaderID );
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
}
