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

void GameLogicComponent::ProcessInput()
{
  for ( auto const& input : m_playerInput )
  {
    if ( input == PlayerInput::e_quit )
    {
      m_messenger.Post({3},{int(GameSignal::e_quit),0});
    }
    else if ( input == PlayerInput::e_moveUp )
    {
      // Set paddle speed up
      MovementData data ( m_movement.GetData( 1 ) );
      data.m_speed[1] = 2.0f;
      m_movement.SetData( 1, data );
    }
    else if ( input == PlayerInput::e_moveDown )
    {
      // Set paddle speed down
      MovementData data ( m_movement.GetData( 1 ) );
      data.m_speed[1] = -2.0f;
      m_movement.SetData( 1, data );
    }
    else if ( input == PlayerInput::e_stopMoving )
    {
      // Set paddle speed 0
      MovementData data ( m_movement.GetData( 1 ) );
      data.m_speed[1] = 0.0f;
      m_movement.SetData( 1, data );
    }
  }
}

void GameLogicComponent::ProcessEvent( GameEvent const& i_event)
{
  switch ( i_event )
  {
    case ( GameEvent::e_ballHitsAIGoalLine ):
    {
      m_playerScore += 1;
      m_messenger.Post({0},{1,m_playerScore});
      m_messenger.Post({3},{int(GameSignal::e_resetLevel),0});
      break;
    }
    case ( GameEvent::e_ballHitsPlayerGoalLine ):
    {
      m_aiScore += 1;
      m_messenger.Post({0},{2,m_aiScore});
      m_messenger.Post({3},{int(GameSignal::e_resetLevel),0});
      break;
    }
    default:
    {
      assert(false);
    }
  }
}