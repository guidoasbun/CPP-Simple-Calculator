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
    font.loadFromFile("Fonts/Roboto-Bold.ttf");
//    if (font.loadFromFile("Fonts/Roboto-Bold.ttf"))
//        std::cout << "ERROR::CALCULATOR::INITFONTS::Failed to load font" << "\n";
}

void Calculator::initDisplayText()
{
    uiText.setFont(font);
    uiText.setCharacterSize(60);
    uiText.setFillColor(sf::Color::White);
    uiText.setString("NONE");
    uiText.setPosition(20.f, 35.f);
}

void Calculator::initDisplay()
{
    display.setPosition(0.f, 0.f);
    display.setSize(sf::Vector2f(600.f, 160.f));
    display.setFillColor(sf::Color::Black);
}

void Calculator::initOperators()
{
    float const yCoordinate = 180.f;
    float xCoordinate = 30.f;

    operators.setSize(sf::Vector2f(120.f, 80.f));
    operators.setFillColor(sf::Color(79,79,79));

    for (int i = 0; i < 4; ++i)
    {
        operators.setPosition(xCoordinate, yCoordinate);
        operatorButtons.push_back(operators);
        xCoordinate += 140.f;
    }
}

void Calculator::initNumbers()
{
    float yCoordinate = 180.f;
    float xCoordinate = 30.f;

    numbers.setSize(sf::Vector2f(120.f, 80.f));
    numbers.setFillColor(sf::Color(150, 150, 150));

    for (int i = 0; i < 12; ++i)
    {
        if (i % 3 == 0)
        {
            xCoordinate = 30.f;
            yCoordinate += 105.f;
        }

        numbers.setPosition(xCoordinate, yCoordinate);
        numberButtons.push_back(numbers);
        if (i == 10)
        {
            numbers.setFillColor(sf::Color(190, 38, 38));
        }
        xCoordinate += 140.f;
    }
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
    initOperators();
    initNumbers();
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

    ss << "0.0";

    uiText.setString(ss.str());
}

void Calculator::update()
{
    pollEvents();
    updateMousePosition();
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

void Calculator::renderOperators(sf::RenderTarget &target)
{
    for (auto &e: operatorButtons)
    {
        target.draw(e);
    }

}

void Calculator::renderNumbers(sf::RenderTarget &target)
{
    for (auto &e : numberButtons)
    {
        target.draw(e);
    }
}

void Calculator::render()
{

    //Sets window with light grey background
    window->clear(sf::Color(204, 204, 204));

    //Draw game objects

    renderDisplay(*window);
    renderDisplayText(*window);
    renderOperators(*window);
    renderNumbers(*window);

    window->display();
}