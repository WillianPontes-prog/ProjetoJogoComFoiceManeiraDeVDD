#include "Jogo.h"
#include<iostream>

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

        window.clear();

        //desenha todas outras entidades
        for (std::list<Plataforma*>::iterator it = listaPlataforma->begin(); it != listaPlataforma->end(); ++it) {
            
            (*it)->atualiza();
        }


        for (std::list<Jogador*>::iterator it = listaJogadores->begin(); it != listaJogadores->end(); ++it) {

            (*it)->atualiza();
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
    }
	
}
