/*
 * File:   GameLogicComponent.cpp
 * Author: juan.garibotti
 *
 * Created on 16 de mayo de 2014, 16:04
 */

#include "GameLogicComponent.hpp"

#include <cassert>
#include "CollisionResolution.hpp"

GameLogicComponent::GameLogicComponent( CollisionResolutionComponent const& i_collisionResolution )
    : m_collisionResolution ( i_collisionResolution )
    , m_playerScore ( 0 )
    , m_aiScore ( 0 )
    , m_signalResetLevel ( false )
{}

void GameLogicComponent::Update()
{
    for ( auto const& event : m_collisionResolution.GetEvents() )
    {
        ProcessEvent( event );
    }
}

void GameLogicComponent::ProcessEvent( GameEvent const& i_event)
{
    switch ( i_event )
    {
        case ( GameEvent::e_ballHitsAIGoalLine ):
        {
            m_playerScore += 1;
            m_signalResetLevel = true;
            break;
        }
        case ( GameEvent::e_ballHitsPlayerGoalLine ):
        {
            m_aiScore += 1;
            m_signalResetLevel = true;
            break;
        }
        default:
        {
            assert(false);
            break;
        }
    }
}

bool const& GameLogicComponent::SignalResetLevel() const
{
    return m_signalResetLevel;
}

void GameLogicComponent::ClearSignal()
{
    m_signalResetLevel = false;
}