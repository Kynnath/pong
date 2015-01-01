/*
 * File:   Movement.hpp
 * Author: juan.garibotti
 *
 * Created on 17 de febrero de 2014, 14:08
 */

#ifndef MOVEMENT_HPP
#define	MOVEMENT_HPP

#include <vector>
#include "VEC/Vector3.hpp"
#include "EntityId.hpp"

struct MovementData
{
  EntityID m_entityID;
  vec::Vector3 m_position;
  vec::Vector3 m_speed;
};

class MovementComponent
{
  std::vector< MovementData > m_data;
  std::vector< MovementData > m_buffer;

  void Swap();

  public:
      void AddEntity( MovementData const& i_data );
      void Update();
      MovementData const& GetData( EntityID const& i_entityID ) const;
      void SetData( EntityID const& i_entityID, MovementData const& i_data );
};

#endif	/* MOVEMENT_HPP */

