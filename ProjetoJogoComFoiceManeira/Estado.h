#pragma once
#pragma once

namespace Entidades {
    namespace Personagens {
        class Zumbinana;
    }
}


class Estado
{
public:
    virtual ~Estado() {}
    virtual void atualiza(Entidades::Personagens::Zumbinana* inimigo) = 0;
    virtual void move(Entidades::Personagens::Zumbinana* inimigo) = 0;
    virtual void sacarArma(Entidades::Personagens::Zumbinana* inimigo) = 0;
    virtual void SwitchState(Entidades::Personagens::Zumbinana* inimigo) = 0;
};
