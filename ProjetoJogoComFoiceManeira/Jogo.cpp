#include "Jogo.h"
#include<iostream>


Jogo::Jogo() :
    window(sf::VideoMode(1920, 1080, 32), "JogoFoiceFodaWOOOOOOOOOOOOOOOOOOOOOOOWN", sf::Style::Default)
{
    Player1 = new Jogador();
    Player1->set_Window(&window);

    fase1 = new Fase(Player1, &window);
    LEs = fase1->getAllEntidade();

    Atualiza();
}

Jogo::~Jogo()
{

}

void Jogo::Atualiza()
{
    /* mostrar FPS
    int frameCount=0;
    sf::Clock clock;
    */

    while (window.isOpen())
    {
        //limitador FPS
        window.setFramerateLimit(60);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        //desenha todas outras entidades
        for (int i = 0; i < LEs->LEs.get_len(); i++) {
            Entidade* temp = LEs->LEs.get_item(i);
         
            temp->atualiza();
        }

        /* Mostrar FPS
        frameCount++;
        if (clock.getElapsedTime().asSeconds() >= 1.f)
        {
            std::cout << "FPS: " << frameCount << std::endl;
            frameCount = 0;
            clock.restart();
        }
        */

        window.display();
    }
	
}
