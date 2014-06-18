/*
 * File:   CollisionDetectionComponent.hpp
 * Author: juan.garibotti
 *
 * Created on 19 de febrero de 2014, 18:03
 */

#ifndef COLLISIONDETECTION_HPP
#define	COLLISIONDETECTION_HPP

#include <vector>
#include "GameLogicComponent.hpp"
#include "EntityId.hpp"

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

struct BoundaryData
{
    float m_top;
    float m_bottom;
    float m_left;
    float m_right;
};

struct BoundaryCheck
{
    EntityID m_entityID;
    enum Side
    {
        e_top,
        e_bottom,
        e_left,
        e_right
    } m_side;
};

typedef std::vector< CollisionPair > CollisionsList;
class MovementComponent;

class CollisionDetectionComponent
{
    MovementComponent const& k_movement;
    std::vector< CollisionData > m_data;
    std::vector< GameEvent > m_eventList;
    CollisionsList m_collisions;
    BoundaryData m_boundaries;
    BoundaryCheck m_boundaryCheck;
    bool m_collisionDetected;

    void ClearEvents();
    void ClearCollisions();

    public:
        CollisionDetectionComponent( MovementComponent const& i_movement );
        void AddEntity( CollisionData const& i_data );
        BoundaryCheck const& GetBoundaryCheck() const;
        CollisionsList const& GetCollisions() const;
        bool const& CollisionDetected() const;
        void Update();
        std::vector< GameEvent > const& GetEvents() const;
};

#endif	/* COLLISIONDETECTIONCOMPONENT_HPP */

