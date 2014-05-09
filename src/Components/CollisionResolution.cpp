/*
 * File:   CollisionResolution.cpp
 * Author: juan.garibotti
 *
 * Created on 21 de febrero de 2014, 17:16
 */

#include "CollisionResolution.hpp"

#include "CollisionDetection.hpp"
#include "Movement.hpp"

CollisionResolutionComponent::CollisionResolutionComponent( MovementComponent & io_movement, CollisionDetectionComponent & io_collisionDetection )
    : m_movement( io_movement )
    , m_collisionDetection ( io_collisionDetection )
{}

void CollisionResolutionComponent::Update()
{
    CollisionsList const& collisions ( m_collisionDetection.GetCollisions() );
    if ( collisions.size() != 0 )
    {
        MovementData entityA ( m_movement.GetData( collisions.front().m_entityIDA ) );
        entityA.m_speed[0] *= -1.0f;
        m_movement.SetData( entityA.m_entityID, entityA );

        MovementData entityB ( m_movement.GetData( collisions.front().m_entityIDB ) );
        entityB.m_speed[0] *= -1.0f;
        m_movement.SetData( entityB.m_entityID, entityB );

        m_collisionDetection.ClearCollisions();
    }
}