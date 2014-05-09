/*
 * File:   Application.hpp
 * Author: juan.garibotti
 *
 * Created on 17 de febrero de 2014, 11:48
 */

#ifndef APPLICATION_HPP
#define	APPLICATION_HPP

#include "SFML/Window.hpp"
#include "Components/AIComponent.hpp"
#include "Components/Movement.hpp"
#include "Components/CollisionDetection.hpp"
#include "Components/CollisionResolution.hpp"
#include "Components/Graphics.hpp"

class Application
{
    bool m_running;
    sf::Window m_window;
    MovementComponent m_movement;
    AIComponent m_ai;
    CollisionDetectionComponent m_collisionDetection;
    CollisionResolutionComponent m_collisionResolution;
    GraphicsComponent m_graphics;

    void SetUp();
    void HandleEvents();
    void Update();
    void Render();
    void CleanUp();

    public:
        Application();
        void Run();
};

#endif	/* APPLICATION_HPP */

