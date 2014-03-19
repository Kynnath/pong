/* 
 * File:   Movement.hpp
 * Author: juan.garibotti
 *
 * Created on 17 de febrero de 2014, 14:08
 */

#ifndef MOVEMENT_HPP
#define	MOVEMENT_HPP

#include <vector>
#include "EntityID.hpp"

struct MovementData
{
    EntityID m_id;
    float m_position[3];
    float m_speed[3];
};

class MovementComponent
{
    std::vector< MovementData > m_data;
    std::vector< MovementData > m_buffer;
    
    void Swap();
    
    public:
        void AddEntity( MovementData const& i_data );
        void Update();
        MovementData const& GetData( EntityID const& i_id ) const;
};

#endif	/* MOVEMENT_HPP */

