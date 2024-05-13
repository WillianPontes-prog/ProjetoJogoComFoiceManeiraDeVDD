#include "Jogo.h"

Jogo::Jogo() :
    window(sf::VideoMode(1920, 1080, 32), "JogoFoiceFodaWOOOOOOOOOOOOOOOOOOOOOOOWN", sf::Style::Default)
{
    Player1 = new Jogador();
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

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        //desenha todas outras entidades
        for (std::list<Plataforma>::iterator it = listaPlataforma->begin(); it != listaPlataforma->end(); ++it) {
            
            it->atualiza();
        }

        for (std::list<Jogador>::iterator it = listaJogadores->begin(); it != listaJogadores->end(); ++it) {

            it->atualiza();
        }



        window.display();
    }
	
}
