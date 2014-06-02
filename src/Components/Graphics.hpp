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

struct GraphicsData // Entity specific
{
    EntityID m_entityID;
    glt::Frame m_frame;
    ModelID m_modelID;
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

namespace glt
{
    struct Model;
}

class GraphicsComponent
{
    std::vector< GraphicsData > m_data;
    std::vector< ModelData > m_models;
    std::vector<GraphicsData> m_elements;
    MovementComponent const& k_movement;
    glt::Shader m_shader;
    glt::GeometryTransform m_geometryTransform;

    public:
        GraphicsComponent( MovementComponent const& i_movement );
        void Initialize();
        void AddModel( ModelID const& i_modelID, glt::Model const& i_model );
        void AddElement( GraphicsData const& i_element );
        void AddEntity( GraphicsData const& i_graphicsData );
        void Update();
        void Render() const;
};

#endif	/* GRAPHICS_HPP */

