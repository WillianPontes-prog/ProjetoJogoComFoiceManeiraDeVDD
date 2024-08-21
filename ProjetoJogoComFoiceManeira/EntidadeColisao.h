#pragma once
#include "Entidade.h"

class EntidadeColisao : public Entidade {
protected:
    int hspd;
    int vspd;
    int vida;

public:
    EntidadeColisao(int posX = 0, int posY = 0, int vida = 5);
    ~EntidadeColisao();

    virtual void move() = 0;
    virtual void atualiza() = 0;

};