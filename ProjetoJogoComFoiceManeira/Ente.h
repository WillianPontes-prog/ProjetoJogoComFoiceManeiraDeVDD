#pragma once
#include<iostream>
#include<string>
#include <SFML/Graphics.hpp>
#include"GerenciadorGrafico.h"

class GerenciadorGrafico;

class Ente {
protected:
    //int id;
    static GerenciadorGrafico* gerenciadorGrafico;
    sf::Texture textura;
    sf::Sprite sprite;

public:
    Ente(GerenciadorGrafico* gerenciadorGrafico) {  };
    ~Ente() {  };
    void setGerenciadorGrafico(GerenciadorGrafico* gerenciadorGrafico) {  };

    void setTextura(std::string s) {
        if (!textura.loadFromFile(s)) {
            // Tratar o erro de carregamento da textura
            throw std::runtime_error("Erro ao carregar a textura!");
        }
        sprite.setTexture(textura);
    };

    void atualizaSprite(float x, float y) {
        sprite.setPosition(x, y);

    };
    sf::Sprite getSprite() { return sprite; };
    virtual void atualiza() = 0;

    void draw() { gerenciadorGrafico->draw(this); };
};