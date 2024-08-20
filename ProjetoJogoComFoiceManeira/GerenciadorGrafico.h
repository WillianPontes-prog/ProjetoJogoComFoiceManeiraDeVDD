#pragma once
#include<iostream>
#include"Ente.h"
#include <SFML/Graphics.hpp>

class Ente;

class GerenciadorGrafico {
private:
    sf::RenderWindow* window;

public:
    GerenciadorGrafico(sf::RenderWindow* w) { this->window = w; };
    ~GerenciadorGrafico() {  };
    void draw(Ente* e);
};
