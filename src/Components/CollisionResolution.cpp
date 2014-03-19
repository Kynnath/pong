/* 
 * File:   CollisionResolution.cpp
 * Author: juan.garibotti
 * 
 * Created on 21 de febrero de 2014, 17:16
 */

#include "CollisionResolution.hpp"

CollisionResolutionComponent::CollisionResolutionComponent( MovementComponent & io_movement, CollisionDetectionComponent const& i_collisionDetection )
    : m_movement( io_movement )
    , k_collisionDetection ( i_collisionDetection )
{}

void CollisionResolutionComponent::Update()
{}