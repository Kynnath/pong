/*
 * File:   AIComponent.cpp
 * Author: juan.garibotti
 *
 * Created on 9 de mayo de 2014, 15:49
 */

#include "AIComponent.hpp"

#include "Movement.hpp"

AIComponent::AIComponent(msg::Messenger & io_messenger, MovementComponent const& i_movement)
  : r_messenger {io_messenger}
  , k_movement {i_movement}
{}

void AIComponent::Update()
{
  // Simple AI: move towards the ball
  MovementData aiData ( k_movement.GetData( 2 ) );
  MovementData ballData ( k_movement.GetData( 3 ) );

  if ( aiData.m_position[1] > ballData.m_position[1] )
  {
    r_messenger.Post({4},{2,2});
  }
  else if ( aiData.m_position[1] < ballData.m_position[1] )
  {
    r_messenger.Post({4},{1,2});
  }
  else
  {
    r_messenger.Post({4},{3,2});
  }
}