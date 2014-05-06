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

}

MovementData const& MovementComponent::GetData( EntityID const& i_id ) const
{
    for ( auto first ( m_data.begin() ), end ( m_data.end() ); first != end; ++first )
    {
        if ( i_id == first->m_id )
        {
            return *first;
        }
    }
    throw std::range_error( "No Entity found" );
}