/*
 * File:   GameLogicComponent.hpp
 * Author: juan.garibotti
 *
 * Created on 16 de mayo de 2014, 16:04
 */

#ifndef GAMELOGICCOMPONENT_HPP
#define	GAMELOGICCOMPONENT_HPP

#include <random>
#include <vector>
#include "MSG/Messenger.hpp"

struct PlayerInput
{
  enum
  {
    e_quit,
    e_moveUp,
    e_moveDown,
    e_stopMoving
  };
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
  std::minstd_rand m_rng;
  msg::Messenger & m_messenger;
  msg::Dequeueer m_scores;
  msg::Dequeueer m_commands;
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
    void ProcessEvent( GameEvent const& i_event );
    void ResetLevel();
};

#endif	/* GAMELOGICCOMPONENT_HPP */

