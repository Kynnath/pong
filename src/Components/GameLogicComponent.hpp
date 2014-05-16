/*
 * File:   GameLogicComponent.hpp
 * Author: juan.garibotti
 *
 * Created on 16 de mayo de 2014, 16:04
 */

#ifndef GAMELOGICCOMPONENT_HPP
#define	GAMELOGICCOMPONENT_HPP

enum class GameEvent
{
    e_ballHitsPlayerGoalLine,
    e_ballHitsAIGoalLine
};

class CollisionResolutionComponent;

class GameLogicComponent
{
    CollisionResolutionComponent const& m_collisionResolution;
    int m_playerScore;
    int m_aiScore;
    bool m_signalResetLevel;

    public:
        GameLogicComponent( CollisionResolutionComponent const& i_collisionResolution );
        int const& GetPlayerScore() const;
        int const& GetAIScore() const;
        void Update();
        void ProcessEvent( GameEvent const& i_event );
        bool const& SignalResetLevel() const;
        void ClearSignal();
};

#endif	/* GAMELOGICCOMPONENT_HPP */

