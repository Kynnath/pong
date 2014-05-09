/*
 * File:   AIComponent.hpp
 * Author: juan.garibotti
 *
 * Created on 9 de mayo de 2014, 15:49
 */

#ifndef AICOMPONENT_HPP
#define	AICOMPONENT_HPP

class MovementComponent;

class AIComponent
{
    MovementComponent & m_movement;

    public:
        AIComponent( MovementComponent & io_movement );
        void Update();
};

#endif	/* AICOMPONENT_HPP */

