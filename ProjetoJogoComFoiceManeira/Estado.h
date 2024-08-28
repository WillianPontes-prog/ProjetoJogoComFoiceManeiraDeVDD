#pragma once
#pragma once

class Zumbinana;

class Estado
{
public:
    virtual ~Estado() {}
    virtual void atualiza(Zumbinana* inimigo) = 0;
    virtual void move(Zumbinana* inimigo) = 0;
    virtual void sacarArma(Zumbinana* inimigo) = 0;
    virtual void SwitchState(Zumbinana* inimigo) = 0;
};
