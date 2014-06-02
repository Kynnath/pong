/*
 * File:   CollisionResolution.cpp
 * Author: juan.garibotti
 *
 * Created on 21 de febrero de 2014, 17:16
 */

#include "CollisionResolution.hpp"

#include <cmath>
#include "CollisionDetection.hpp"
#include "Movement.hpp"

void ResolveBallPaddleCollision( MovementData & io_ball, MovementData & io_paddle );

CollisionResolutionComponent::CollisionResolutionComponent( MovementComponent & io_movement, CollisionDetectionComponent & io_collisionDetection )
    : m_movement( io_movement )
    , m_collisionDetection ( io_collisionDetection )
{}

void ResolveBallPaddleCollision( MovementData & io_ball, MovementData & io_paddle )
{
    // Entity A is the ball
    // Move ball to paddle's reference frame
    io_ball.m_speed.Subtract( io_paddle.m_speed );
    io_ball.m_position.Subtract( io_paddle.m_position );

    // Determine x and y collision time
    auto collisionTimeX = ( 1.0f - std::abs( io_ball.m_position[0] ) ) / std::abs( io_ball.m_speed[0] );
    auto collisionTimeY = ( 2.5f - std::abs( io_ball.m_position[1] ) ) / std::abs( io_ball.m_speed[1] );

    if ( collisionTimeX < collisionTimeY )
    {
        // collision happened from front
        io_ball.m_speed[0] = -io_ball.m_speed[0];
        io_ball.m_speed[1] += io_paddle.m_speed[1];
        if ( io_ball.m_position[0] < 0.0f )
        {
            io_ball.m_position[0] -= 1.0f - std::abs( io_ball.m_position[0] );
        }
        else
        {
            io_ball.m_position[0] += 1.0f - std::abs( io_ball.m_position[0] );
        }
    }
    else
    {
        io_ball.m_speed[1] = -io_ball.m_speed[1];
        if ( io_ball.m_position[1] < 0.0f )
        {
            io_ball.m_position[1] -= ( 2.5f - std::abs( io_ball.m_position[1] ) );// / 2.0f;
            io_paddle.m_position[1] += ( 2.5f - std::abs( io_ball.m_position[1] ) );// / 2.0f;
        }
        else
        {
            io_ball.m_position[1] += ( 2.5f - std::abs( io_ball.m_position[1] ) );// / 2.0f;
            io_paddle.m_position[1] -= ( 2.5f - std::abs( io_ball.m_position[1] ) );// / 2.0f;
        }
    }

    // Return ball to game frame of reference
    io_ball.m_position.Add( io_paddle.m_position );

}

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
            if ( boundaryCheck.m_side == BoundaryCheck::e_top )
            {
                paddle.m_position[1] = 8.0f;
            }
            else if ( boundaryCheck.m_side == BoundaryCheck::e_bottom )
            {
                paddle.m_position[1] = -8.0f;
            }
            paddle.m_speed[1] = 0.0f;
            m_movement.SetData( paddle.m_entityID, paddle );
        }
    }
    else
    {
        CollisionsList const& collisions ( m_collisionDetection.GetCollisions() );
        if ( collisions.size() != 0 )
        {
            // Identify ball

            auto entityA = m_movement.GetData( collisions.front().m_entityIDA );
            auto entityB = m_movement.GetData( collisions.front().m_entityIDB );

            if ( entityA.m_entityID == 3 )
            {
                ResolveBallPaddleCollision( entityA, entityB );
                m_movement.SetData( entityA.m_entityID, entityA );
            }
            else
            {
                ResolveBallPaddleCollision( entityB, entityA );
                m_movement.SetData( entityB.m_entityID, entityB );
            }
        }
    }
}