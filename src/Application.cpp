/*
 * File:   Application.cpp
 * Author: juan.garibotti
 *
 * Created on 17 de febrero de 2014, 11:48
 */

#include "Application.hpp"

#include "GL/glew.h"
#include "CFG/Config.hpp"
#include "GLT/Model.hpp"
#include "OBJ/Object.hpp"


Application::Application()
    : m_running ( false )
    , m_window ()
    , m_movement ()
    , m_collisionDetection ( m_movement )
    , m_collisionResolution ( m_movement, m_collisionDetection )
    , m_graphics ( m_movement )
{}

void Application::Run()
{
    SetUp();

    while ( m_running )
    {
        HandleEvents();
        Update();
        Render();
    }

    CleanUp();
}

void Application::SetUp()
{
    // Load configuration
    cfg::Config const config ( "default.conf" );

    // Create the window
    {
        int const xResolution ( config.GetIntProperty( "Window::xResolution" ) );
        int const yResolution ( config.GetIntProperty( "Window::yResolution" ) );
        std::string const title ( config.GetStringProperty( "Window::title" ) );

        sf::VideoMode const mode ( (unsigned int)xResolution , (unsigned int)yResolution );

        m_window.create( mode, title );
    }

    m_graphics.Initialize();
    m_graphics.AddModel( glt::Model( obj::Object( "resource/model/paddle.obj" ) ) );

    m_running = true;
}

void Application::HandleEvents()
{
    sf::Event event;
    while ( m_window.pollEvent( event ) )
    {
        if ( event.type == sf::Event::Closed )
            m_running = false;
    }
}

void Application::Update()
{
    m_movement.Update();
    m_collisionDetection.Update();
    m_collisionResolution.Update();
    m_graphics.Update();
}

void Application::Render()
{
    m_graphics.Render();
    m_window.display();
}

void Application::CleanUp()
{
    m_window.close();
}

