#include "Jogo.h"
#include<iostream>
#include"Menu.h"

#define FPS 60

//descomente abaixo para mostrar o FPS
//#define SHOW_FPS

Jogo::Jogo() :
    window(sf::VideoMode(960, 640, 32), "JogoFoiceFodaWOOOOOOOOOOOOOOOOOOOOOOOWN", sf::Style::Default)
{


    //menu/////////////////////////////////////////////////////////////////////
    menu = new Menu(this);
    menu->set_Window(&window);

    //fases////////////////////////////////////////////////////////////////////
    fase1 = new Fase(&window, "pipipipopopodeteste.json");

    listaPlataforma = fase1->get_listaPlataforma();
    listaJogadores = fase1->get_listaJogadores();
    listaInimigos = fase1->get_listaInimigos();


    ///////////////////////////////////////////////////////////////////////////
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
        case Jogo::MenuInicial: {
            menu->atualiza();
        }
        break;
        case Jogo::EmJogo: {
            fase1->atualiza();
        }
        break;
        default: {
        }
        break;
        }







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
        window.clear();
    }

}
