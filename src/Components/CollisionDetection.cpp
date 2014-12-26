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

CollisionDetectionComponent::CollisionDetectionComponent( msg::Messenger & i_messenger, MovementComponent const& i_movement )
  : r_messenger {i_messenger}
  , k_movement ( i_movement )
  , m_boundaries ( { 10.0f, -10.0f, -16.0f, 16.0f } )
  , m_boundaryCheck ( { 0, BoundaryCheck::e_bottom } )
  , m_collisionDetected ( false )
{}

BoundaryCheck const& CollisionDetectionComponent::GetBoundaryCheck() const
{
  return m_boundaryCheck;
}

CollisionsList const& CollisionDetectionComponent::GetCollisions() const
{
  return m_collisions;
}

bool const& CollisionDetectionComponent::CollisionDetected() const
{
  return m_collisionDetected;
}

void CollisionDetectionComponent::ClearCollisions()
{
  m_collisions.clear();
  m_boundaryCheck.m_entityID = 0;
  m_collisionDetected = false;
}

void CollisionDetectionComponent::Update()
{
  ClearCollisions();
  ClearEvents();
  for ( auto entity ( m_data.begin() ), end ( m_data.end() ); entity != end; ++entity )
  {
    MovementData const& entityMovData ( k_movement.GetData( entity->m_entityID ) );

    if ( entityMovData.m_position[0] + entity->m_sizeX > m_boundaries.m_right )
    {
      // Player scores a point
      r_messenger.Post({1},{int(GameEvent::e_ballHitsAIGoalLine),0});
      m_eventList.push_back( GameEvent::e_ballHitsAIGoalLine );
    }
    else if ( entityMovData.m_position[0] - entity->m_sizeX < m_boundaries.m_left )
    {
      // AI scores a point
      r_messenger.Post({1},{int(GameEvent::e_ballHitsPlayerGoalLine),0});
      m_eventList.push_back( GameEvent::e_ballHitsPlayerGoalLine );
    }
    else if ( entityMovData.m_position[1] + entity->m_sizeY > m_boundaries.m_top )
    {
      m_boundaryCheck.m_entityID = entity->m_entityID;
      m_boundaryCheck.m_side = BoundaryCheck::e_top;
      m_collisionDetected = true;
    }
    else if ( entityMovData.m_position[1] - entity->m_sizeY < m_boundaries.m_bottom )
    {
      m_boundaryCheck.m_entityID = entity->m_entityID;
      m_boundaryCheck.m_side = BoundaryCheck::e_bottom;
      m_collisionDetected = true;
    }

    for ( auto collider ( entity+1 ); collider != end; ++collider )
    {
      MovementData const& colliderMovData ( k_movement.GetData( collider->m_entityID ) );

      if ( std::abs( entityMovData.m_position[0] - colliderMovData.m_position[0] ) < ( entity->m_sizeX + collider->m_sizeX ) &&
           std::abs( entityMovData.m_position[1] - colliderMovData.m_position[1] ) < ( entity->m_sizeY + collider->m_sizeY ) )
      {
        m_collisions.push_back( CollisionPair( entity->m_entityID, collider->m_entityID ) );
        m_collisionDetected = true;
      }
    }
  }
}

std::vector< GameEvent > const& CollisionDetectionComponent::GetEvents() const
{
  return m_eventList;
}

void CollisionDetectionComponent::ClearEvents()
{
  m_eventList.clear();
}