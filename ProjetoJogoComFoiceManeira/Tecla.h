#pragma once
#include <SFML/Graphics.hpp>

class Tecla {

private:
    static int isPJump;

public:

    Tecla() {}
    ~Tecla() {};

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



