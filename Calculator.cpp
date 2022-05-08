//
// Created by Guido Asbun on 5/7/22.
//

#include "Calculator.h"

//Private functions
void Calculator::initVariables()
{
    window = nullptr;
}

void Calculator::initWindow()
{
    videoMode.height = 1200;
    videoMode.width = 1400;

    window = new sf::RenderWindow(videoMode, "Calculator 1", sf::Style::Titlebar | sf::Style::Close);
}

//Constructors / Destructors
Calculator::Calculator()
{
    initVariables();
    initWindow();
}

Calculator::~Calculator()
{
    delete window;
}

//Accessors
const bool Calculator::running() const
{
    return window->isOpen();
}

//Functions
void Calculator::pollEvents()
{
    //Event polling
    while (window->pollEvent(ev))
    {
        switch (ev.type)
        {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape)
                    window->close();
                break;
        }
    }
}

void Calculator::update()
{
    pollEvents();
}

void Calculator::render()
{
    /*
     * @return void
     * - clear old frame
     * - render objects
     * - display frame in window
     * Renders the game objects
     */
    window->clear(sf::Color(204, 204, 204, 0));

    //Draw game objects

    window->display();
}








