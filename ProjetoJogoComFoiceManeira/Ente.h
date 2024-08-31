#pragma once
#include<iostream>
#include<string>
#include <SFML/Graphics.hpp>
#include"Gerenciadores/GerenciadorGrafico.h"


namespace Gerenciadores { class GerenciadorGrafico; }

class Ente {

protected:
    
    Gerenciadores::GerenciadorGrafico* gerenciadorGrafico;
    sf::Texture* textura;
    sf::Sprite sprite;

public:
    Ente();
    ~Ente();
    void setGerenciadorGrafico();



    void atualizaSprite(float x, float y) {

        if (textura != NULL) {
            sprite.setPosition(x + (textura->getSize().x / 2), y + (textura->getSize().y / 2));
        }

    }

    sf::Sprite getSprite() { return sprite; }
    void setScale(int i){ sprite.setScale(i, 1); }
    virtual void atualiza() = 0;
    virtual void draw();

};