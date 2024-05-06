#include "Jogo.h"

Jogo::Jogo() :
	window(sf::VideoMode(1920, 1080, 32), "JogoFoiceFodaWOOOOOOOOOOOOOOOOOOOOOOOWN", sf::Style::Default)
{
    Player1.set_Window(&window);
    Malvadao.set_Window(&window);

    Atualiza();
}

Jogo::~Jogo()
{

}

void Jogo::Atualiza()
{

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        Player1.Move();
        Player1.draw();
        Malvadao.draw();

        window.display();
    }
	
}
