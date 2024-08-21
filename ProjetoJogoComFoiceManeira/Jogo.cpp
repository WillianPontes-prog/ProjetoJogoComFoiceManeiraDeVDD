#include "Jogo.h"

#define FPS 60


Jogo::Jogo():
	gerenciadorGrafico(new GerenciadorGrafico()),
    f1(new Fase1(gerenciadorGrafico))
{

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

        f1->atualiza();

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
