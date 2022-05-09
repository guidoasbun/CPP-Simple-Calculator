//
// Created by Guido Asbun on 5/7/22.
//

#include "Calculator.h"

//Private functions
void Calculator::initVariables()
{
    window = nullptr;

    //Calculator Logic

}

void Calculator::initWindow()
{
    videoMode.height = 700;
    videoMode.width = 600;

    window = new sf::RenderWindow(videoMode, "CPP Calculator", sf::Style::Titlebar | sf::Style::Close);

    window->setFramerateLimit(60);
}

void Calculator::initFonts()
{
    if (font.loadFromFile("Fonts/Roboto-Bold.ttf"))
        std::cout << "ERROR::GAME::INITFONTS::Failed to load font" << "\n";
}

void Calculator::initDisplayText()
{
    uiText.setFont(font);
    uiText.setCharacterSize(100);
    uiText.setFillColor(sf::Color::White);
    uiText.setString("NONE");
    uiText.setPosition(496.f, 20.f);
}

void Calculator::initDisplay()
{
    display.setPosition(0.f, 0.f);
    display.setSize(sf::Vector2f(600.f, 160.f));
    display.setFillColor(sf::Color::Black);
}

//Constructors / Destructors
Calculator::Calculator()
{
    initVariables();
    initWindow();
    initDisplayText();
    //Initialize
    initFonts();
    initDisplay();
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

//Update Functions
void Calculator::updateMousePosition()
{
    mousePosWindow = sf::Mouse::getPosition(*window);
    mousePosView = window->mapPixelToCoords(mousePosWindow);
}

void Calculator::updateDisplayText()
{
    std::stringstream ss;

    ss << "0";

    uiText.setString(ss.str());
}

void Calculator::update()
{
    pollEvents();
    updateDisplayText();
}

//Render functions
void Calculator::renderDisplayText(sf::RenderTarget &target)
{
    target.draw(uiText);
}

void Calculator::renderDisplay(sf::RenderTarget& target)
{
    target.draw(display);
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
    //Sets window with light grey background
    window->clear(sf::Color(204, 204, 204, 0));

    //Draw game objects


    renderDisplay(*window);
    renderDisplayText(*window);

    window->display();
}








