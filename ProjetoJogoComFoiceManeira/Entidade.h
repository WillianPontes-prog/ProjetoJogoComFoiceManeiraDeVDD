#pragma once
#include "Ente.h"

#define GRAVIDADE 0.5

class Entidade : public Ente {
protected:
    sf::RectangleShape body;

public:
    Entidade(float posX = 0, float posY = 0, float tamX = 32, float tamY = 32);
    ~Entidade();
    virtual void atualiza() = 0;
    sf::RectangleShape getBody() { return body; };
    sf::RectangleShape* getBodyPtr() { return &body; };
    void setPosition(sf::Vector2f pos) { body.setPosition(pos); };
    
    void drawBody() { gerenciadorGrafico->draw(body); };

   
};