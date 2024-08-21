#pragma once
#include<iostream>
#include"Ente.h"
#include <SFML/Graphics.hpp>

class Ente;

class GerenciadorGrafico {
private:
    sf::RenderWindow* window;

public:
    GerenciadorGrafico() ;
    ~GerenciadorGrafico();

    void draw(Ente* e);
    void draw(sf::Sprite s);

    void atualiza();

    sf::RenderWindow* getWindow() { return window; };
};
