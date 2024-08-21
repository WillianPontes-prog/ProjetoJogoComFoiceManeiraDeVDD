#include "GerenciadorDeComandos.h"

int GerenciadorDeComandos::isPJump = 0;

int GerenciadorDeComandos::Left()   { return sf::Keyboard::isKeyPressed(sf::Keyboard::A); }
int GerenciadorDeComandos::Right()  { return sf::Keyboard::isKeyPressed(sf::Keyboard::D); }
int GerenciadorDeComandos::Down()   { return sf::Keyboard::isKeyPressed(sf::Keyboard::S); }
int GerenciadorDeComandos::Up()     { return sf::Keyboard::isKeyPressed(sf::Keyboard::W); }
int GerenciadorDeComandos::Click()  { return sf::Keyboard::isKeyPressed(sf::Keyboard::Z); }

int GerenciadorDeComandos::Jump() {
    
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



int GerenciadorDeComandos::BasicAtk()       { return sf::Keyboard::isKeyPressed(sf::Keyboard::Z); }
int GerenciadorDeComandos::SpecialAtk()     { return sf::Keyboard::isKeyPressed(sf::Keyboard::X); }
int GerenciadorDeComandos::ChangeWeapon()   { return sf::Keyboard::isKeyPressed(sf::Keyboard::Tab); }