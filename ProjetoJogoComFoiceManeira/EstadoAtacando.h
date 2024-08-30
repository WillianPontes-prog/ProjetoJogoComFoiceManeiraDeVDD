#pragma once
#pragma once
#include "Estado.h"

class EstadoAtacando : public Estado
{
public:
    void atualiza(Personagens::Zumbinana* inimigo) override;
    void move(Personagens::Zumbinana* inimigo) override;
    void sacarArma(Personagens::Zumbinana* inimigo) override;
    void SwitchState(Personagens::Zumbinana* inimigo) override;
};