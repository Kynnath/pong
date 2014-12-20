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

GameLogicComponent::GameLogicComponent( msg::Messenger & i_messenger, CollisionDetectionComponent const& i_collisionDetection, MovementComponent & i_movement )
  : m_messenger ( i_messenger )
  , k_collisionDetection ( i_collisionDetection )
  , m_movement ( i_movement )
  , m_playerScore ( 0 )
  , m_aiScore ( 0 )
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
  for ( auto const& event : k_collisionDetection.GetEvents() )
  {
    ProcessEvent( event );
  }
}

void GameLogicComponent::PushInput( PlayerInput const& i_input )
{
  m_playerInput.push_back( i_input );
}

void GameLogicComponent::ProcessInput()
{
  ClearSignals();
  for ( auto const& input : m_playerInput )
  {
    if ( input == PlayerInput::e_quit )
    {
      m_signal.push_back( GameSignal::e_quit );
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
      m_messenger.Post({1,m_playerScore});
      m_signal.push_back( GameSignal::e_resetLevel );
      break;
    }
    case ( GameEvent::e_ballHitsPlayerGoalLine ):
    {
      m_aiScore += 1;
      m_messenger.Post({2,m_aiScore});
      m_signal.push_back( GameSignal::e_resetLevel );;
      break;
    }
    default:
    {
      assert(false);
    }
  }
}

void GameLogicComponent::ClearSignals()
{
  m_signal.clear();
}

std::vector<GameSignal> const& GameLogicComponent::GetSignals() const
{
  return m_signal;
}