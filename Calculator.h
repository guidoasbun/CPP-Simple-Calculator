//
// Created by Rodrigo Asbun on 5/7/22.
//
/*
 * class that acts as the game engine
 * w
 */
#include <iostream>
#include <vector>
#include <sstream>

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

    //Mouse positions
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    //Text
    sf::Font font;
    sf::Text uiText;

    //Calculator Logic


    //Calculator Objects
    sf::RectangleShape display;
    sf::RectangleShape operators;
    std::vector<sf::RectangleShape> operatorButtons;
    sf::RectangleShape numbers;
    std::vector<sf::RectangleShape> numberButtons;
    sf::RectangleShape equals;

    //Private Functions
    void initVariables();
    void initWindow();
    void initDisplay();
    void initFonts();
    void initDisplayText();
    void initOperators();
    void initNumbers();
    void initEquals();
public:
    //Constructors / Destructors
    Calculator();
    virtual ~Calculator();

    //Accessors
    const bool running() const;

    //Functions
    void pollEvents();

    void updateMousePosition();
    void updateDisplayText();
    void update();

    void renderDisplayText(sf::RenderTarget& target);
    void renderDisplay(sf::RenderTarget& target);
    void renderOperators(sf::RenderTarget& target);
    void renderNumbers(sf::RenderTarget& target);
    void renderEquals(sf::RenderTarget& target);
    void render();
};


#endif //SFMLTEMPLATE_GAME_H
