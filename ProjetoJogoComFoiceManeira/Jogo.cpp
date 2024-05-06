#include "Jogo.h"

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

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (int i = 0; i < LEs->LEs.get_len(); i++) {
            Entidade* temp = LEs->LEs.get_item(i);
            


            temp->atualiza();
        }

        window.display();
    }
	
}
