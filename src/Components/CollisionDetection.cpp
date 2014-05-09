/*
 * File:   CollisionDetectionComponent.cpp
 * Author: juan.garibotti
 *
 * Created on 19 de febrero de 2014, 18:03
 */

#include "CollisionDetection.hpp"

#include <cmath>
#include "Movement.hpp"

CollisionPair::CollisionPair( EntityID const& i_entityIDA, EntityID const& i_entityIDB )
    : m_entityIDA ( i_entityIDA )
    , m_entityIDB ( i_entityIDB )
{}

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

void CollisionDetectionComponent::ClearCollisions()
{
    m_collisions.clear();
}

void CollisionDetectionComponent::Update()
{
    for ( auto entity ( m_data.begin() ), end ( m_data.end() ); entity != end; ++entity )
    {
        MovementData const& entityMovData ( k_movement.GetData( entity->m_entityID ) );

        for ( auto collider ( entity+1 ); collider != end; ++collider )
        {
            MovementData const& colliderMovData ( k_movement.GetData( collider->m_entityID ) );

            if ( std::abs( entityMovData.m_position[0] - colliderMovData.m_position[0] ) < ( entity->m_sizeX + collider->m_sizeX ) &&
                 std::abs( entityMovData.m_position[1] - colliderMovData.m_position[1] ) < ( entity->m_sizeY + collider->m_sizeY ) )
            {
                m_collisions.push_back( CollisionPair( entity->m_entityID, collider->m_entityID ) );
            }
        }
    }
}