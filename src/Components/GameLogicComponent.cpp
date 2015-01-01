/*
 * File:   GameLogicComponent.cpp
 * Author: juan.garibotti
 *
 * Created on 16 de mayo de 2014, 16:04
 */

#include "GameLogicComponent.hpp"

#include <cassert>
#include "CollisionResolution.hpp"
#include "Movement.hpp"

GameLogicComponent::GameLogicComponent( msg::Messenger & i_messenger, MovementComponent & i_movement )
  : m_messenger { i_messenger }
  , m_scores { m_messenger.Register({1}) }
  , m_commands { m_messenger.Register({4}) }
  , m_movement { i_movement }
  , m_playerScore { 0 }
  , m_aiScore { 0 }
{}

int const& GameLogicComponent::GetPlayerScore() const
{
  return m_playerScore;
}

int const& GameLogicComponent::GetAiScore() const
{
  return m_aiScore;
}

void GameLogicComponent::Update()
{
  while (!m_commands.IsEmpty())
  {
    switch ( m_commands.Front().m_id )
    {
      case PlayerInput::e_moveUp:
      {
        // Set paddle speed up
        MovementData data ( m_movement.GetData( m_commands.Front().m_value ) );
        data.m_speed[1] = 2.0f;
        m_movement.SetData( m_commands.Front().m_value, data );
        break; 
      }
      case PlayerInput::e_moveDown:
      {
        // Set paddle speed down
        MovementData data ( m_movement.GetData( m_commands.Front().m_value ) );
        data.m_speed[1] = -2.0f;
        m_movement.SetData( m_commands.Front().m_value, data );
        break;
      }
      case PlayerInput::e_stopMoving:
      {
        // Set paddle speed 0
        MovementData data ( m_movement.GetData( m_commands.Front().m_value ) );
        data.m_speed[1] = 0.0f;
        m_movement.SetData( m_commands.Front().m_value, data );
        break;
      }
      default:
        break;
    }
    m_commands.Pop();
  }
  while (!m_scores.IsEmpty())
  {
    ProcessEvent( GameEvent(m_scores.Front().m_id) );
    m_scores.Pop();
  }
}

void GameLogicComponent::PushInput( PlayerInput const& i_input )
{
  m_playerInput.push_back( i_input );
}

void GameLogicComponent::ProcessEvent( GameEvent const& i_event)
{
  switch ( i_event )
  {
    case ( GameEvent::e_ballHitsAIGoalLine ):
    {
      m_playerScore += 1;
      m_messenger.Post({0},{1,m_playerScore});
      ResetLevel();
      break;
    }
    case ( GameEvent::e_ballHitsPlayerGoalLine ):
    {
      m_aiScore += 1;
      m_messenger.Post({0},{2,m_aiScore});
      ResetLevel();
      break;
    }
    default:
    {
      assert(false);
    }
  }
}

void GameLogicComponent::ResetLevel()
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
    std::uniform_real_distribution<> speedY ( -3.0f,  3.0f );
    std::uniform_real_distribution<> speedX ( -2.0f, -4.0f );
    movementData.m_speed = vec::Vector3{ speedX(m_rng), speedY(m_rng), 0.0 };
    m_movement.SetData( 3, movementData );
}