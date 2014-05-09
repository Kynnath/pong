/*
 * File:   AIComponent.cpp
 * Author: juan.garibotti
 *
 * Created on 9 de mayo de 2014, 15:49
 */

#include "AIComponent.hpp"

#include "Movement.hpp"

AIComponent::AIComponent( MovementComponent & io_movement )
    : m_movement ( io_movement )
{}

void AIComponent::Update()
{
    // Simple AI: move towards the ball
    MovementData aiData ( m_movement.GetData( 2 ) );
    MovementData ballData ( m_movement.GetData( 3 ) );

    if ( aiData.m_position[1] > ballData.m_position[1] )
    {
        aiData.m_speed[1] = -2.0f;
    }
    else if ( aiData.m_position[1] < ballData.m_position[1] )
    {
        aiData.m_speed[1] = 2.0f;
    }
    else
    {
        aiData.m_speed[1] = 0.0f;
    }

    m_movement.SetData( 2, aiData );
}