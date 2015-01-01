/*
 * File:   AIComponent.hpp
 * Author: juan.garibotti
 *
 * Created on 9 de mayo de 2014, 15:49
 */

#ifndef AICOMPONENT_HPP
#define	AICOMPONENT_HPP

#include "MSG/Messenger.hpp"

class MovementComponent;

class AIComponent
{
  msg::Messenger & r_messenger;
  MovementComponent & m_movement;

  public:
    AIComponent(msg::Messenger & io_messenger, MovementComponent & io_movement);
    void Update();
};

#endif	/* AICOMPONENT_HPP */

