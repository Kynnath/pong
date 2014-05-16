/*
 * File:   CollisionResolution.hpp
 * Author: juan.garibotti
 *
 * Created on 21 de febrero de 2014, 17:16
 */

#ifndef COLLISIONRESOLUTION_HPP
#define	COLLISIONRESOLUTION_HPP

#include <vector>
#include "CollisionDetection.hpp"
#include "GameLogicComponent.hpp"


class MovementComponent;
class CollisionDetectionComponent;

class CollisionResolutionComponent
{
    MovementComponent & m_movement;
    CollisionDetectionComponent const& m_collisionDetection;
    std::vector< GameEvent > m_eventList;

    void ClearEvents();

    public:
        CollisionResolutionComponent( MovementComponent & io_movement, CollisionDetectionComponent & io_collisionDetection );
        std::vector< GameEvent > const& GetEvents() const;
        void Update();

};

#endif	/* COLLISIONRESOLUTION_HPP */

