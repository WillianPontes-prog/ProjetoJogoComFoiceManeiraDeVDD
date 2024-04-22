#include "Window.h"
#include <SFML/Graphics.hpp>

Window::Window()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "JogoFoiceFodaWOOOOOOOOOOOOOOOOOOOOOOOWN", sf::Style::Default);

    sf::RectangleShape shape(sf::Vector2f(100.f, 150.f));
    sf::RectangleShape shape2(sf::Vector2f(100.f, 150.f));

    shape.setFillColor(sf::Color::Blue);
    shape2.setFillColor(sf::Color::Red);

    shape.setPosition(sf::Vector2f(0.f, 0.f));
    shape2.setPosition(sf::Vector2f(1820.f, 930.f));

    if (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(shape);
        window.draw(shape2);

        window.display();
    }

}
