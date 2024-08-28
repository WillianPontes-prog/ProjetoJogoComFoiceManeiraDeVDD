#include "Jogo.h"
#include "Fase1.h"
#include "Fase2.h"

#define FPS 60


Jogo::Jogo():
	gerenciadorGrafico(GerenciadorGrafico::getInstance()),
    f1(nullptr),
    f2(nullptr),
    menu(new Menu(this))
{
    srand(time(NULL));
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

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
            if(rodando == Jogo::_fase1){
                f1->salvarFase();
			}

			rodando = Jogo::_menu;
		}

        switch (rodando)
        {
        case Jogo::_menu:
            menu->fases = false;
            menu->atualiza();

            break;
        case Jogo::_menuFases:
            menu->fases = true;
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

void Jogo::CriaFase1(bool n, bool carregar = false)
{
    if (!f1) { delete f1; } 

    f1 = new Fase1(n, this, carregar);

}

void Jogo::CriaFase2(bool n, bool carregar)
{
    if (!f2) { delete f2; }

    f2 = new Fase2(n, this, carregar);

    
}
