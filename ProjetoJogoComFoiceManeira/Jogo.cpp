#include "Jogo.h"

#define FPS 60


Jogo::Jogo():
	gerenciadorGrafico(GerenciadorGrafico::getInstance()),
    f1(nullptr),
    f2(nullptr),
    menu(new Menu(this))
{
	rodando = Jogo::_menu;
	executar();
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{
#ifdef SHOW_FPS
    //mostrar FPS
    int frameCount = 0;
    sf::Clock clock;
#endif // SHOW_FPS

    sf::RenderWindow* window = gerenciadorGrafico->getWindow();

    window->setFramerateLimit(FPS);

    while (window->isOpen())
    {
        //limitador FPS
        window->setFramerateLimit(FPS);

        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        switch (rodando)
        {
        case Jogo::_menu:

            menu->atualiza();

            break;
        case Jogo::_fase1:

            f1->atualiza();

            break;
        case Jogo::_fase2:

            f2->atualiza();

            break;
        default:



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

        window->display();

    }
}
