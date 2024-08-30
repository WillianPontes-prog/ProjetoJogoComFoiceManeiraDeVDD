#pragma once
#pragma once

namespace Personagens {
    class Zumbinana;
}

class Estado
{
public:
    virtual ~Estado() {}
    virtual void atualiza(Personagens::Zumbinana* inimigo) = 0;
    virtual void move(Personagens::Zumbinana* inimigo) = 0;
    virtual void sacarArma(Personagens::Zumbinana* inimigo) = 0;
    virtual void SwitchState(Personagens::Zumbinana* inimigo) = 0;
};
