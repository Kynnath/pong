/*
 * File:   GameLogicComponent.hpp
 * Author: juan.garibotti
 *
 * Created on 16 de mayo de 2014, 16:04
 */

#ifndef GAMELOGICCOMPONENT_HPP
#define	GAMELOGICCOMPONENT_HPP

#include <vector>

enum class PlayerInput
{
    e_moveUp,
    e_moveDown,
    e_stopMoving,
    e_quit
};

enum class GameSignal
{
    e_quit,
    e_resetLevel
};

enum class GameEvent
{
    e_ballHitsPlayerGoalLine,
    e_ballHitsAIGoalLine
};

class MovementComponent;
class CollisionDetectionComponent;

class GameLogicComponent
{
    CollisionDetectionComponent const& k_collisionDetection;
    MovementComponent & m_movement;
    std::vector<PlayerInput> m_playerInput;
    std::vector<GameSignal> m_signal;
    int m_playerScore;
    int m_aiScore;

    void ClearSignals();

    public:
        GameLogicComponent( CollisionDetectionComponent const& i_collisionDetection, MovementComponent & i_movement );
        int const& GetPlayerScore() const;
        int const& GetAIScore() const;
        void Update();
        void PushInput( PlayerInput const& i_input );
        void ProcessInput();
        void ProcessEvent( GameEvent const& i_event );
        std::vector<GameSignal> const& GetSignals() const;
};

#endif	/* GAMELOGICCOMPONENT_HPP */

