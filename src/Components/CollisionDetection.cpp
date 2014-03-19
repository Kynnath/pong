/* 
 * File:   CollisionDetectionComponent.cpp
 * Author: juan.garibotti
 * 
 * Created on 19 de febrero de 2014, 18:03
 */

#include "CollisionDetection.hpp"

void CollisionDetectionComponent::AddEntity( CollisionData const& i_data )
{
    m_data.push_back( i_data );
}

CollisionDetectionComponent::CollisionDetectionComponent( MovementComponent const& i_movement )
    : k_movement ( i_movement )
{}

CollisionsList const& CollisionDetectionComponent::GetCollisions() const
{
    return m_collisions;
}

void CollisionDetectionComponent::Update()
{
    /*for ( auto first ( m_data.begin() ), end ( m_data.end() ); first != end; ++first )
    {
        MovementData const& movData1 ( r_movement.GetData( first->m_id ) );
        for ( auto second ( first+1 ); second != end; ++second )
        {
            //const int xDiff (  )
            //if ( )
        }
    }*/
}