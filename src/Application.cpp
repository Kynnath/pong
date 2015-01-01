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
#include "GUI/GameData.hpp"
#include "OBJ/Object.hpp"


Application::Application()
  : m_commands {m_messenger.Register({4})}
  , m_window {}
  , m_movement {}
  , m_ai {m_messenger, m_movement}
  , m_collisionDetection {m_messenger, m_movement}
  , m_collisionResolution {m_movement, m_collisionDetection}
  , m_gameLogic {m_messenger, m_movement}
  , m_graphics {m_movement, m_gameLogic}
  , m_interface {m_messenger}
  , m_running {false}
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
    sf::ContextSettings const context { 0, 0, 0, 3, 2 };

    m_window.create( mode, title, sf::Style::None, context );

    m_window.setFramerateLimit( (unsigned int)config.GetIntProperty( "Window::framerate" ) );
    m_window.setKeyRepeatEnabled( false );
  }
  // Load resources
  {
    GraphicsSettings const graphicsSettings = { config.GetStringProperty( "Catalog::models" ),
                                                config.GetStringProperty( "Catalog::shaders" ),
                                                config.GetStringProperty( "Catalog::textures" ) };
    m_graphics.Initialize( graphicsSettings );

    m_graphics.AddModel( config.GetIntProperty( "Resource::Paddle::id" ),
                         glt::Model( obj::Object( config.GetStringProperty( "Resource::Paddle::model" ) ) ) );
    m_graphics.AddModel( config.GetIntProperty( "Resource::Ball::id" ),
                         glt::Model( obj::Object( config.GetStringProperty( "Resource::Ball::model" ) ) ) );
    m_graphics.AddModel( 3, glt::Model( obj::Object( config.GetStringProperty( "Resource::Numbers::model" ) ) ) );
    m_graphics.AddTexture( "Id1" );

  }
  // Initialize interface
  {
    // Commands: exit, move up, move down, stop
    m_interface.Init({4},{0,1,2,3});
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
      1, // ModelID
      0
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
    graphicsData.m_id = config.GetIntProperty( "Entity::AIPaddle::id" );
    collisionData.m_entityID = config.GetIntProperty( "Entity::AIPaddle::id" );
    m_movement.AddEntity( movementData );
    m_graphics.AddEntity( graphicsData );
    m_collisionDetection.AddEntity( collisionData );

    movementData.m_entityID = config.GetIntProperty( "Entity::Ball::id" );
    movementData.m_position[0] = config.GetFloatProperty( "Entity::Ball::positionX" );
    movementData.m_speed[0] = -2.0f;
    movementData.m_speed[1] = -0.5f;
    graphicsData.m_id = config.GetIntProperty( "Entity::Ball::id" );
    graphicsData.m_modelID = config.GetIntProperty( "Entity::Ball::modelID" );
    collisionData.m_entityID = config.GetIntProperty( "Entity::Ball::id" );
    collisionData.m_sizeX = 0.5f;
    collisionData.m_sizeY = 0.5f;
    m_movement.AddEntity( movementData );
    m_graphics.AddEntity( graphicsData );
    m_collisionDetection.AddEntity( collisionData );
  }
  // Load interface
  {
    GraphicsData graphicsData =
    {
      4,  // entity id player score
      { { { -8, 8, 0 } }, { { 0, 0, 1 } }, { { 0, 1, 0 } } }, // Frame
      3, // ModelID for numbers
      0
    };
    m_graphics.AddElement( graphicsData );

    graphicsData.m_id = 5; // AI score id
    graphicsData.m_frame.m_position = { 8, 8, 0 };
    m_graphics.AddElement( graphicsData );
  }

  m_running = true;

  m_gameLogic.ResetLevel();
}

void Application::ProcessInput()
{
  sf::Event event;
  while ( m_window.pollEvent( event ) )
  {
    m_interface.ProcessInput(event);
  }
  ProcessCommands();
}

void Application::Update()
{
  m_ai.Update();
  
  m_gameLogic.Update();
  
  
  m_movement.Update();
  m_collisionDetection.Update();
  while ( m_collisionDetection.CollisionDetected() )
  {
    m_collisionResolution.Update();
    m_collisionDetection.Update();
  }

  m_graphics.Update();
  m_interface.Update();
}

void Application::Render()
{
    m_graphics.Render();
    m_interface.Draw();
    m_window.display();
}

void Application::CleanUp()
{
    m_window.close();
}

void Application::ProcessCommands()
{
  while (!m_commands.IsEmpty())
  {
    switch (m_commands.Front().m_id)
    {
      case PlayerInput::e_quit:
        m_running = false;
        break;
      default:
        break;
    }
    m_commands.Pop();
  }
}