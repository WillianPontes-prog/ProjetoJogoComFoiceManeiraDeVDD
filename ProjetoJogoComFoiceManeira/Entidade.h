#pragma once
#include "Ente.h"
#include "json.hpp"


#define GRAVIDADE 0.5
using json = nlohmann::json;
class Entidade : public Ente {
protected:
    sf::RectangleShape body;

public:

    enum Tipo {
        _jogador,
        _jogador2,
        _zumbifriorento,
		_zumbidragao,
		_zumbinana,
		_plataforma,
        _obstaculoTeleporte,
        _obstaculoDano
    };

    Entidade(float posX = 0, float posY = 0, float tamX = 32, float tamY = 32);
    ~Entidade();
    virtual void atualiza() = 0;
    sf::RectangleShape getBody() { return body; };
    sf::RectangleShape* getBodyPtr() { return &body; };
    void setPosition(sf::Vector2f pos) { body.setPosition(pos); };
    
    void drawBody() { 
        gerenciadorGrafico->draw(body); 
    };
    virtual json toJson() = 0;

   
};