#pragma once
#include<iostream>
#include"Ente.h"


#include <SFML/Graphics.hpp>

class GerenciadorGrafico {
private:
    sf::RenderWindow* w;

public:
    GerenciadorGrafico() { 
        w = new sf::RenderWindow();
    };

    ~GerenciadorGrafico() {  };
    void draw(Ente* e) { w->draw(e->getSprite()); };
};