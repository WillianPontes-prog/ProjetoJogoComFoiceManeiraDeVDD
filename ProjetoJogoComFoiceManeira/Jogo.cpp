#include "Jogo.h"
#include<iostream>
#include"Menu.h"

#define FPS 60

//descomente abaixo para mostrar o FPS
//#define SHOW_FPS

Jogo::Jogo() :
    window(sf::VideoMode(1920, 1080, 32), "JogoFoiceFodaWOOOOOOOOOOOOOOOOOOOOOOOWN", sf::Style::Default)
{
    Player1 = new Jogador(50,50);
    Player1->set_Window(&window);

    fase1 = new Fase(Player1, &window);
    listaPlataforma = fase1->get_listaPlataforma();
    listaJogadores = fase1->get_listaJogadores();
    listaInimigos = fase1->get_listaInimigos();


    Atualiza();
}

Jogo::~Jogo()
{

}

void Jogo::Atualiza()
{
#ifdef SHOW_FPS
    //mostrar FPS
    int frameCount = 0;
    sf::Clock clock;
#endif // SHOW_FPS

    while (window.isOpen())
    {
        //limitador FPS
        window.setFramerateLimit(FPS);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        switch (state)
        {
        case Jogo::InitialMenu: {
            ;
        }
            break;
        case Jogo::InGame: {
            fase1->atualiza();
        }
            break;
        default: {
        }
            break;
        }
        window.clear();

        
        
#ifdef SHOW_FPS
        /* Mostrar FPS*/
        frameCount++;
        if (clock.getElapsedTime().asSeconds() >= 1.f)
        {
            std::cout << "FPS: " << frameCount << std::endl;
            frameCount = 0;
            clock.restart();
        }
#endif


        window.display();
    }
	
}
