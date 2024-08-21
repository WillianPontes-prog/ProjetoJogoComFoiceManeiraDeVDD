#include "GerenciadorDeComandos.h"

int GerenciadorDeComandos::isPJump = 0;

int GerenciadorDeComandos::Esquerda()   { return sf::Keyboard::isKeyPressed(sf::Keyboard::A); }
int GerenciadorDeComandos::Direita()  { return sf::Keyboard::isKeyPressed(sf::Keyboard::D); }
int GerenciadorDeComandos::Baixo()   { return sf::Keyboard::isKeyPressed(sf::Keyboard::S); }
int GerenciadorDeComandos::Cima()     { return sf::Keyboard::isKeyPressed(sf::Keyboard::W); }
int GerenciadorDeComandos::Click()  { return sf::Keyboard::isKeyPressed(sf::Keyboard::Z); }

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



int GerenciadorDeComandos::Disparar()       { return sf::Keyboard::isKeyPressed(sf::Keyboard::Z); }
