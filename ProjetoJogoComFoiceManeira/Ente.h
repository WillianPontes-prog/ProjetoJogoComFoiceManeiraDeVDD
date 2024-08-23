#pragma once
#include<iostream>
#include<string>
#include <SFML/Graphics.hpp>
#include"GerenciadorGrafico.h"

class GerenciadorGrafico;

class Ente {

protected:
    
    GerenciadorGrafico* gerenciadorGrafico;
    sf::Texture* textura;
    sf::Sprite sprite;

public:
    Ente();
    ~Ente();
    void setGerenciadorGrafico(GerenciadorGrafico* gerenciadorGrafico);

    void setTextura(std::string s) {
        /*
        if (!textura->loadFromFile(s)) {
            // Tratar o erro de carregamento da textura
            throw std::runtime_error("Erro ao carregar a textura!");
        }
        sprite.setOrigin(textura->getSize().x / 2, textura->getSize().y / 2); //centraliza o sprite
        sprite.setTexture(*textura);

        atualizaSprite(0, 0);
        //*/
    }

    void atualizaSprite(float x, float y) {

        if (textura != NULL) {
            sprite.setPosition(x + (textura->getSize().x / 2), y + (textura->getSize().y / 2));
        }

    }
    
    sf::Sprite getSprite() { return sprite; }
    
    virtual void atualiza() = 0;
    virtual void draw();
};