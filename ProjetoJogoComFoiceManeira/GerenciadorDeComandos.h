#pragma once
#include <SFML/Graphics.hpp>

class GerenciadorDeComandos {

private:
    static int isPJump;

public:

    GerenciadorDeComandos() {}
    ~GerenciadorDeComandos() {};

    static int Left();
    static int Right();
    static int Down();
    static int Up();
    static int Click();

    static int Jump();

    static int BasicAtk();
    static int SpecialAtk();
    static int ChangeWeapon();

    
};