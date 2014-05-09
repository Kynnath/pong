/*
 * File:   Movement.cpp
 * Author: juan.garibotti
 *
 * Created on 17 de febrero de 2014, 14:08
 */

#include <stdexcept>

#include "Movement.hpp"

void MovementComponent::AddEntity( MovementData const& i_data )
{
    m_data.push_back( i_data );
}

void MovementComponent::Swap()
{
    std::swap( m_data, m_buffer );
}

void MovementComponent::Update()
{
    // Update time is 1/60th of a second, or 16.7 ms
    // Speed is in units/second
    for ( auto & entity : m_data )
    {
        entity.m_position[0] += entity.m_speed[0] * ( 1.0f / 60.f );
        entity.m_position[1] += entity.m_speed[1] * ( 1.0f / 60.f );
        entity.m_position[2] += entity.m_speed[2] * ( 1.0f / 60.f );
    }
}

MovementData const& MovementComponent::GetData( EntityID const& i_entityID ) const
{
    for ( auto const& entity : m_data )
    {
        if ( i_entityID == entity.m_entityID )
        {
            return entity;
        }
    }
    throw std::range_error( "No Entity found" );
}

void MovementComponent::SetData( EntityID const& i_entityID, MovementData const& i_data )
{
    for ( auto & entity : m_data )
    {
        if ( i_entityID == entity.m_entityID )
        {
            entity = i_data;
            return;
        }
    }
    throw std::range_error( "No Entity found" );
}