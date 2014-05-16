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
    : m_window ()
    , m_movement ()
    , m_ai ( m_movement )
    , m_collisionDetection ( m_movement )
    , m_collisionResolution ( m_movement, m_collisionDetection )
    , m_gameLogic ( m_collisionResolution )
    , m_graphics ( m_movement )
    , m_running ( false )
{}

void Application::Run()
{
    SetUp();

    while ( m_running )
    {
        ProcessInput();
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
        int const& resolutionX ( config.GetIntProperty( "Window::resolutionX" ) );
        int const& resolutionY ( config.GetIntProperty( "Window::resolutionY" ) );
        std::string const& title ( config.GetStringProperty( "Window::title" ) );

        sf::VideoMode const mode ( (unsigned int)resolutionX , (unsigned int)resolutionY );

        m_window.create( mode, title );

        m_window.setFramerateLimit( (unsigned int)config.GetIntProperty( "Window::framerate" ) );
        m_window.setKeyRepeatEnabled( false );
    }

    {
    // Load resources
        m_graphics.Initialize();
        m_graphics.AddModel( config.GetIntProperty( "Resource::Paddle::id" ),
                             glt::Model( obj::Object( config.GetStringProperty( "Resource::Paddle::model" ) ) ) );
        m_graphics.AddModel( config.GetIntProperty( "Resource::Ball::id" ),
                             glt::Model( obj::Object( config.GetStringProperty( "Resource::Ball::model" ) ) ) );
        m_graphics.AddModel( 3, glt::Model( obj::Object( "resource/model/numbers.obj" ) ) );
    }

    // Load entities
    {
        MovementData movementData =
        {
            config.GetIntProperty( "Entity::PlayerPaddle::id" ),
            {
                config.GetFloatProperty( "Entity::PlayerPaddle::positionX" ),
                config.GetFloatProperty( "Entity::PlayerPaddle::positionY" ),
                config.GetFloatProperty( "Entity::PlayerPaddle::positionZ" )
            },
            {
                0.0f, 0.0f, 0.0f
            }
        };
        GraphicsData graphicsData =
        {
            1,  // entity id
            { { { 0, 0, 0 } }, { { 0, 0, 1 } }, { { 0, 1, 0 } } }, // Frame
            1 // ModelID
        };
        CollisionData collisionData =
        {
            1, // entity id
            0.5f, 2.0f // size x, y
        };

        m_movement.AddEntity( movementData );
        m_graphics.AddEntity( graphicsData );
        m_collisionDetection.AddEntity( collisionData );

        movementData.m_entityID = config.GetIntProperty( "Entity::AIPaddle::id" );
        movementData.m_position[0] = config.GetFloatProperty( "Entity::AIPaddle::positionX" );
        graphicsData.m_entityID = config.GetIntProperty( "Entity::AIPaddle::id" );
        collisionData.m_entityID = config.GetIntProperty( "Entity::AIPaddle::id" );
        m_movement.AddEntity( movementData );
        m_graphics.AddEntity( graphicsData );
        m_collisionDetection.AddEntity( collisionData );

        movementData.m_entityID = config.GetIntProperty( "Entity::Ball::id" );
        movementData.m_position[0] = config.GetFloatProperty( "Entity::Ball::positionX" );
        movementData.m_speed[0] = -2.0f;
        movementData.m_speed[1] = -0.5f;
        graphicsData.m_entityID = config.GetIntProperty( "Entity::Ball::id" );
        graphicsData.m_modelID = config.GetIntProperty( "Entity::Ball::modelID" );
        collisionData.m_entityID = config.GetIntProperty( "Entity::Ball::id" );
        collisionData.m_sizeX = 0.5f;
        collisionData.m_sizeY = 0.5f;
        m_movement.AddEntity( movementData );
        m_graphics.AddEntity( graphicsData );
        m_collisionDetection.AddEntity( collisionData );

        // UI
        movementData.m_speed[0] = 0.0f;
        movementData.m_speed[1] = 0.0f;
        movementData.m_entityID = 4;
        graphicsData.m_entityID = 4;
        graphicsData.m_modelID = 3;
        m_movement.AddEntity( movementData );
        m_graphics.AddEntity( graphicsData );

    }

    m_running = true;
}

void Application::ProcessInput()
{
    sf::Event event;
    while ( m_window.pollEvent( event ) )
    {
        if ( event.type == sf::Event::Closed )
            m_running = false;

        else if ( event.type == sf::Event::KeyPressed )
        {
            if ( event.key.code == sf::Keyboard::Up )
            {
                // Set paddle speed up
                MovementData data ( m_movement.GetData( 1 ) );
                data.m_speed[1] = 2.0f;
                m_movement.SetData( 1, data );
            }
            else if ( event.key.code == sf::Keyboard::Down )
            {
                // Set paddle speed down
                MovementData data ( m_movement.GetData( 1 ) );
                data.m_speed[1] = -2.0f;
                m_movement.SetData( 1, data );
            }
        }

        else if ( event.type == sf::Event::KeyReleased )
        {
            if ( event.key.code == sf::Keyboard::Up ||
                 event.key.code == sf::Keyboard::Down )
            {
                // Set paddle speed 0
                MovementData data ( m_movement.GetData( 1 ) );
                data.m_speed[1] = 0.0f;
                m_movement.SetData( 1, data );
            }
        }
    }
}

void Application::Update()
{
    m_ai.Update();
    m_movement.Update();
    m_collisionDetection.Update();
    while ( m_collisionDetection.CollisionDetected() )
    {
        m_collisionResolution.Update();
        m_gameLogic.Update();
        if ( m_gameLogic.SignalResetLevel() )
        {
            ResetLevel();
            m_gameLogic.ClearSignal();
        }
        m_collisionDetection.Update();
    }
    m_graphics.Update();
}

void Application::Render()
{
    m_graphics.Render();
    m_interface.Render();
    m_window.display();
}

void Application::CleanUp()
{
    m_window.close();
}

void Application::ResetLevel()
{
    MovementData movementData =
    {
        1,
        {
            -15.0f, 0.0f, 0.0f
        },
        {
            0.0f, 0.0f, 0.0f
        }
    };
    m_movement.SetData( 1, movementData );

    movementData.m_entityID = 2;
    movementData.m_position[0] = 15.0f;
    m_movement.SetData( 2, movementData );

    movementData.m_entityID = 3;
    movementData.m_position[0] = 0.0f;
    movementData.m_speed = vec::Vector3{ -2.0f, 1.0f, 0.0 };
    m_movement.SetData( 3, movementData );
}