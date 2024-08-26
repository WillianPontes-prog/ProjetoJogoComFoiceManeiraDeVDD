#pragma once
#pragma once

class Inimigo2;

class Estado
{
public:
    virtual ~Estado() {}
    virtual void atualiza(Inimigo2* inimigo) = 0;
    virtual void move(Inimigo2* inimigo) = 0;
    virtual void sacarArma(Inimigo2* inimigo) = 0;
    virtual void SwitchState(Inimigo2* inimigo) = 0;
};
