/*
 * File:   GameLogicComponent.hpp
 * Author: juan.garibotti
 *
 * Created on 16 de mayo de 2014, 16:04
 */

#ifndef GAMELOGICCOMPONENT_HPP
#define	GAMELOGICCOMPONENT_HPP

#include <vector>
#include "MSG/Messenger.hpp"

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
  msg::Messenger & m_messenger;
  msg::Dequeueer m_scores;
  MovementComponent & m_movement;
  std::vector<PlayerInput> m_playerInput;
  int m_playerScore;
  int m_aiScore;

  public:
    GameLogicComponent( msg::Messenger & i_messenger, MovementComponent & i_movement );
    int const& GetPlayerScore() const;
    int const& GetAiScore() const;
    void Update();
    void PushInput( PlayerInput const& i_input );
    void ProcessInput();
    void ProcessEvent( GameEvent const& i_event );
};

#endif	/* GAMELOGICCOMPONENT_HPP */

