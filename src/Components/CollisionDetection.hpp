/*
 * File:   CollisionDetectionComponent.hpp
 * Author: juan.garibotti
 *
 * Created on 19 de febrero de 2014, 18:03
 */

#ifndef COLLISIONDETECTION_HPP
#define	COLLISIONDETECTION_HPP

#include <vector>
#include "EntityID.hpp"

struct CollisionPair
{
    EntityID m_entityIDA;
    EntityID m_entityIDB;

    CollisionPair( EntityID const& i_entityIDA, EntityID const& i_entityIDB );
};

struct CollisionData
{
    EntityID m_entityID;
    float m_sizeX;
    float m_sizeY;
};

typedef std::vector< CollisionPair > CollisionsList;
class MovementComponent;

class CollisionDetectionComponent
{
    MovementComponent const& k_movement;
    std::vector< CollisionData > m_data;
    CollisionsList m_collisions;

    public:
        CollisionDetectionComponent( MovementComponent const& i_movement );
        void AddEntity( CollisionData const& i_data );
        CollisionsList const& GetCollisions() const;
        void ClearCollisions();
        void Update();
};

#endif	/* COLLISIONDETECTIONCOMPONENT_HPP */

