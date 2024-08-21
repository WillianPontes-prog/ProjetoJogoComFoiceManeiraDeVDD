#pragma once
#include "Entidade.h"

class EntidadeColisao : public Entidade {
protected:

    float velocidade;

    float hspd;
    float vspd;

    int vida;

    bool noChao;

public:
    EntidadeColisao(int posX = 0, int posY = 0, int vida = 5);
    ~EntidadeColisao();

    void setVelocidade(float velocidade) { this->velocidade = velocidade; };

    virtual void move() = 0;
    virtual void atualiza() = 0;

    float getHspd() { return hspd; };
    float getVspd() { return vspd; };

    void setHspd(float hspd) { this->hspd = hspd; };
    void setVspd(float vspd) { this->vspd = vspd; };

    void setNoChao(bool noChao) { this->noChao = noChao; };

    void drawVida(float posX, float poY, sf::Sprite sprVida);

    void operator--() { vida--; };
};