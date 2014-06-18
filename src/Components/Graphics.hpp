/*
 * File:   Graphics.hpp
 * Author: juan.garibotti
 *
 * Created on 24 de febrero de 2014, 14:36
 */

#ifndef GRAPHICS_HPP
#define	GRAPHICS_HPP

#include "CFG/Config.hpp"
#include "GL/glew.h"
#include "GLT/Frame.hpp"
#include "GLT/Shader.hpp"
#include "GLT/GeometryTransform.hpp"
#include "GLT/Texture.hpp"
#include "GameLogicComponent.hpp"
#include "ModelId.hpp"
#include "Movement.hpp"
#include "ShaderId.hpp"
#include "TextureId.hpp"

struct GraphicsSettings
{
    std::string m_modelCatalog;
    std::string m_shaderCatalog;
    std::string m_textureCatalog;
};

struct GraphicsData // Entity specific
{
    EntityID m_entityID;
    glt::Frame m_frame;
    ModelID m_modelID;
    TextureID m_textureID;
};

struct ModelData // Shared between entities with the same model
{
    ModelID m_modelID;
    GLuint m_vertexArray;
    GLenum m_mode;              // Kind of primitives to render
 	GLsizei m_count;            // Number of elements
 	GLenum m_type;              // Type of the values in m_indices
 	GLvoid const* m_indices;    // For VBOs, offset into index array
};

struct TextureData
{
    TextureID m_textureID;
    std::string m_filename;
    GLuint m_name;
};

namespace glt
{
    struct Model;
}

class GraphicsComponent
{
    std::vector< GraphicsData > m_data;
    std::vector< ModelData > m_models;
    std::vector< GraphicsData > m_elements;
    std::vector< glt::Texture > m_texes;
    std::vector< glt::Shader > m_shaders;
    MovementComponent const& k_movement;
    GameLogicComponent const& k_gameLogic;
    glt::GeometryTransform m_geometryTransform;
    cfg::Config m_modelCatalog;
    cfg::Config m_shaderCatalog;
    cfg::Config m_textureCatalog;

    std::size_t playerScoreOffset;
    std::size_t aiScoreOffset;

    public:
        GraphicsComponent( MovementComponent const& i_movement, GameLogicComponent const& i_gameLogic );
        void Initialize( GraphicsSettings const& i_settings );
        void AddModel( ModelID const& i_modelID, glt::Model const& i_model );
        void AddElement( GraphicsData const& i_element );
        void AddTexture( TextureData const& i_texture );
        void AddEntity( GraphicsData const& i_graphicsData );
        void Update();
        void Render() const;
};

#endif	/* GRAPHICS_HPP */

