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
    EntityID m_idA;
    EntityID m_idB;
};

struct CollisionData
{
    EntityID m_id;
    int m_sizeX;
    int m_sizeY;
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
        void Update();
};

#endif	/* COLLISIONDETECTIONCOMPONENT_HPP */

