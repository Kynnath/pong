/*
 * File:   Graphics.hpp
 * Author: juan.garibotti
 *
 * Created on 24 de febrero de 2014, 14:36
 */

#ifndef GRAPHICS_HPP
#define	GRAPHICS_HPP

#include "GL/glew.h"
#include "GLT/Frame.hpp"
#include "GLT/Shader.hpp"
#include "GLT/GeometryTransform.hpp"
#include "ModelID.hpp"
#include "Movement.hpp"
#include "TextureID.hpp"

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
    std::vector< TextureData > m_textures;
    std::vector< glt::Shader > m_shaders;
    MovementComponent const& k_movement;
    glt::GeometryTransform m_geometryTransform;

    public:
        GraphicsComponent( MovementComponent const& i_movement );
        void Initialize();
        void AddModel( ModelID const& i_modelID, glt::Model const& i_model );
        void AddElement( GraphicsData const& i_element );
        void AddTexture( TextureData const& i_texture );
        void AddEntity( GraphicsData const& i_graphicsData );
        void Update();
        void Render() const;
};

#endif	/* GRAPHICS_HPP */

