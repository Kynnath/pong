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
    for ( auto & entity : m_data )
    {

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