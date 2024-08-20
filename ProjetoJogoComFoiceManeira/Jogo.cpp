#include "Jogo.h"
#include<iostream>
#include"Menu.h"

#define FPS 60

//descomente abaixo para mostrar o FPS
//#define SHOW_FPS

GerenciadorGrafico* Jogo::gerenciadorGrafico = new GerenciadorGrafico();

Jogo::Jogo()
{


    // Resolução original
    sf::Vector2u originalResolution(960, 640);

    // Obtém a resolução atual da tela
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    sf::Vector2u screenResolution(desktopMode.width, desktopMode.height);

    // Calcula a escala para manter a proporção
    float scaleX = static_cast<float>(screenResolution.x) / originalResolution.x;
    float scaleY = static_cast<float>(screenResolution.y) / originalResolution.y;
    float scale = std::min(scaleX, scaleY);

    // Calcula o tamanho da janela mantendo a proporção
    sf::Vector2u windowSize(
        static_cast<unsigned int>(originalResolution.x * scale),
        static_cast<unsigned int>(originalResolution.y * scale)
    );

    // Calcula a posição para centralizar a janela no modo fullscreen
    sf::Vector2i windowPosition(
        (screenResolution.x - windowSize.x) / 2,
        (screenResolution.y - windowSize.y) / 2
    );

    // Cria a janela no modo fullscreen
    window = new sf::RenderWindow(
        sf::VideoMode(screenResolution.x, screenResolution.y),
        "Meu Jogo em Fullscreen",
        sf::Style::Fullscreen
    );

    // Define a view para escalar o conteúdo corretamente
    sf::View view(sf::FloatRect(0, 0, originalResolution.x, originalResolution.y));
    view.setViewport(sf::FloatRect(
        static_cast<float>(windowPosition.x) / screenResolution.x,
        static_cast<float>(windowPosition.y) / screenResolution.y,
        static_cast<float>(windowSize.x) / screenResolution.x,
        static_cast<float>(windowSize.y) / screenResolution.y
    ));

    window->setView(view);
    //menu/////////////////////////////////////////////////////////////////////
    menu = new Menu(this);
    menu->set_Window(window);

    //fases////////////////////////////////////////////////////////////////////
    fase1 = new Fase("pipipipopopodeteste.json");

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

    window->clear();

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


        window->display();
        
    }

}
