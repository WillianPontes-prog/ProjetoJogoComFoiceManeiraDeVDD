#pragma once
#include<iostream>
#include "Ente.h"
#include <SFML/Graphics.hpp>

class Ente;

class GerenciadorGrafico {
private:
    sf::RenderWindow* window;

    void carregarTexturas();

    sf::Texture* tJogador1;
    sf::Texture* tInimigo1;
    sf::Texture* tFase1;
    sf::Texture* tFase1Plat;

    sf::Texture* tFasePlataforma;


public:
    GerenciadorGrafico() ;
    ~GerenciadorGrafico();

    void draw(Ente* e);
    void draw(sf::Sprite s);
    void draw(sf::RectangleShape b);
    void draw(sf::Text t);
    void Close();

    void atualiza();

    sf::RenderWindow* getWindow() { return window; };

    sf::Texture* devolveImagemEnte(Ente* e = NULL);

    
};
