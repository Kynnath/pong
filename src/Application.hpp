/*
 * File:   Application.hpp
 * Author: juan.garibotti
 *
 * Created on 17 de febrero de 2014, 11:48
 */

#ifndef APPLICATION_HPP
#define	APPLICATION_HPP

#include "SFML/Window.hpp"
#include "GUI/Interface.hpp"
#include "MSG/Messenger.hpp"
#include "Components/AIComponent.hpp"
#include "Components/CollisionDetection.hpp"
#include "Components/CollisionResolution.hpp"
#include "Components/GameLogicComponent.hpp"
#include "Components/Graphics.hpp"
#include "Components/Movement.hpp"

class Application
{
  msg::Messenger m_messenger;
  msg::Dequeueer m_commands;
  sf::Window m_window;
  MovementComponent m_movement;
  AIComponent m_ai;
  CollisionDetectionComponent m_collisionDetection;
  CollisionResolutionComponent m_collisionResolution;
  GameLogicComponent m_gameLogic;
  GraphicsComponent m_graphics;
  gui::Interface m_interface;
  bool m_running;

  void SetUp();
  void ProcessInput();
  void Update();
  void Render();
  void CleanUp();

  void ProcessCommands();

  public:
    Application();
    void Run();
};

#endif	/* APPLICATION_HPP */

