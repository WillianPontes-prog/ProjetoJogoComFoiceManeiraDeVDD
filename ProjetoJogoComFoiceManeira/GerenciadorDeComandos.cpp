#include "GerenciadorDeComandos.h"

int GerenciadorDeComandos::isPJump = 0;
int GerenciadorDeComandos::isPJumpV2 = 0;

int GerenciadorDeComandos::Esquerda() { return sf::Keyboard::isKeyPressed(sf::Keyboard::A); }
int GerenciadorDeComandos::EsquerdaV2() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Left); }

int GerenciadorDeComandos::Direita() { return sf::Keyboard::isKeyPressed(sf::Keyboard::D); }
int GerenciadorDeComandos::DireitaV2() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Right); }

int GerenciadorDeComandos::Baixo() { return sf::Keyboard::isKeyPressed(sf::Keyboard::S); }
int GerenciadorDeComandos::BaixoV2() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Down); }

int GerenciadorDeComandos::Cima() { return sf::Keyboard::isKeyPressed(sf::Keyboard::W); }
int GerenciadorDeComandos::CimaV2() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Up); }

int GerenciadorDeComandos::Pular() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !isPJump)
    {
        isPJump = 1;
        return sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    }
    else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        isPJump = 0;
    }

    return 0;
}

int GerenciadorDeComandos::PularV2() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !isPJumpV2)
    {
        isPJumpV2 = 1;
        return sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    }
    else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        isPJumpV2 = 0;
    }

    return 0;
}

int GerenciadorDeComandos::Disparar() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Z); }
int GerenciadorDeComandos::DispararV2() { return sf::Keyboard::isKeyPressed(sf::Keyboard::M); }

int GerenciadorDeComandos::Click() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Z); }