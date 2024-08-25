#include "GerenciadorGrafico.h"

#include "Jogador.h"
#include "Inimigo.h"
#include "Fase1.h"


#define SPR_JOGADOR1 "imagens/jogador1.png"

#define SPR_INIMIGO1 "imagens/inimigo1Zumbi.png"

#define SPR_BCK_FASE1 "imagens/BCK_fase1.png"

#define SPR_BCK_FASE1_PLAT "imagens/Fase_1.png"


void GerenciadorGrafico::carregarTexturas()
{


    if (!tJogador1->loadFromFile(SPR_JOGADOR1)) {
        throw std::runtime_error("Erro ao carregar a textura!");
    }

    if(!tFase1->loadFromFile(SPR_BCK_FASE1) ){
		throw std::runtime_error("Erro ao carregar a textura!");
	}

    if(!tInimigo1->loadFromFile(SPR_INIMIGO1)){
        throw std::runtime_error("Erro ao carregar a textura!");
    }
    
}

GerenciadorGrafico::GerenciadorGrafico():
    tJogador1(new sf::Texture()),
    tFase1(new sf::Texture()),
    tInimigo1(new sf::Texture())
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

    carregarTexturas();
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

sf::Texture* GerenciadorGrafico::devolveImagemEnte(Ente* e)
{
    Jogador* j = dynamic_cast<Jogador*>(e);

    if (j) {
        if (!j->getJogador2())
            return tJogador1;
        else
            return NULL;
    }

    Inimigo* i = dynamic_cast<Inimigo*>(e);
    if (i) {
		return tInimigo1;
	}

    Fase1* f = dynamic_cast<Fase1*>(e);
    if (f) {
		return tFase1;
	}
    
    




    return NULL;;
}



void GerenciadorGrafico::Close()
{
	window->close();
}