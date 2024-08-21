#pragma once
#include "Ente.h"

class Entidade : public Ente {
protected:
    sf::RectangleShape body;

public:
    Entidade(float posX = 0, float posY = 0, float tamX = 32, float tamY = 32);
    ~Entidade();
    virtual void atualiza() = 0;
    sf::RectangleShape getBody() { return body; };

    
};