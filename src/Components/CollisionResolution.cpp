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
    BoundaryCheck const& boundaryCheck ( m_collisionDetection.GetBoundaryCheck() );
    if ( boundaryCheck.m_entityID != 0 )
    {
        if ( boundaryCheck.m_entityID == 3 )
        {
            MovementData ball ( m_movement.GetData( boundaryCheck.m_entityID ) );
            if ( boundaryCheck.m_side == BoundaryCheck::e_top || boundaryCheck.m_side == BoundaryCheck::e_bottom )
            {
                ball.m_position[1] -= ball.m_speed[1] / 60.0f;
                ball.m_speed[1] *= -1.0f;
                m_movement.SetData( ball.m_entityID, ball );
            }
        }
        else
        {
            MovementData paddle ( m_movement.GetData( boundaryCheck.m_entityID ) );
            if ( boundaryCheck.m_side == BoundaryCheck::e_top || boundaryCheck.m_side == BoundaryCheck::e_bottom )
            {
                paddle.m_position[1] -= paddle.m_speed[1] / 60.0f;
                paddle.m_speed[1] = 0.0f;
                m_movement.SetData( paddle.m_entityID, paddle );
            }
        }
    }
    else
    {
        CollisionsList const& collisions ( m_collisionDetection.GetCollisions() );
        if ( collisions.size() != 0 )
        {
            MovementData entityA ( m_movement.GetData( collisions.front().m_entityIDA ) );
            entityA.m_position[0] -= entityA.m_speed[0] / 60.0f;
            entityA.m_speed[0] *= -1.0f;
            m_movement.SetData( entityA.m_entityID, entityA );

            MovementData entityB ( m_movement.GetData( collisions.front().m_entityIDB ) );
            entityB.m_position[0] -= entityB.m_speed[0] / 60.0f;
            entityB.m_speed[0] *= -1.0f;
            m_movement.SetData( entityB.m_entityID, entityB );
        }
    }
}