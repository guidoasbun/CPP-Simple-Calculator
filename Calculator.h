//
// Created by Rodrigo Asbun on 5/7/22.
//
/*
 * class that acts as the game engine
 * w
 */

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#ifndef GAME_H
#define GAME_H

class Calculator
{
private:
    //Variables
    //Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    //Calculator Objects
    sf::RectangleShape display;
    sf::RectangleShape operators;
    sf::RectangleShape numbers;

    //Private Functions
    void initVariables();
    void initWindow();
public:
    //Constructors / Destructors
    Calculator();
    virtual ~Calculator();

    //Accessors
    const bool running() const;

    //Functions
    void pollEvents();
    void update();
    void render();
};


#endif //SFMLTEMPLATE_GAME_H
