#pragma once
#include<iostream>
#include "Ente.h"

#include <SFML/Graphics.hpp>

class Ente;


class GerenciadorGrafico {
private:
    sf::RenderWindow* window;

    void carregarTexturas();

    sf::Texture* tMenu;

    sf::Texture* tJogador1;
    sf::Texture* tJogador2;

    sf::Texture* tInimigo1;
    sf::Texture* tInimigo2;

    sf::Texture* tFase1;
    sf::Texture* tFase1Plat;
    sf::Texture* tFase2Plat;

    sf::Texture* tTeleportador;
    sf::Texture* tFogo;
    sf::Texture* tPlataforma;

    sf::Texture* tChefao;
    
    
    GerenciadorGrafico();

    static GerenciadorGrafico* instance;

public:

    ~GerenciadorGrafico();

    static GerenciadorGrafico* getInstance() {
        if (instance == nullptr) {
            instance = new GerenciadorGrafico();
        }
        return instance;
    }

    void draw(Ente* e);
    void draw(sf::Sprite s);
    void draw(sf::RectangleShape b);
    void draw(sf::Text t);
    void Close();

    void atualiza();

    sf::RenderWindow* getWindow() { return window; };

    sf::Texture* devolveImagemEnte(Ente* e = NULL);

    
};

