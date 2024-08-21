#include "GerenciadorGrafico.h"



GerenciadorGrafico::GerenciadorGrafico()
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

}

GerenciadorGrafico::~GerenciadorGrafico()
{
}

void GerenciadorGrafico::draw(Ente* e)
{
	window->draw(e->getSprite());
}

void GerenciadorGrafico::draw(sf::Sprite s)
{
    window->draw(s);
}

void GerenciadorGrafico::draw(sf::RectangleShape b)
{
	window->draw(b);
}

void GerenciadorGrafico::atualiza()
{

}



