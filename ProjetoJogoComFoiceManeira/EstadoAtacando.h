#pragma once
#pragma once
#include "Estado.h"

class EstadoAtacando : public Estado
{
public:
    void atualiza(Zumbinana* inimigo) override;
    void move(Zumbinana* inimigo) override;
    void sacarArma(Zumbinana* inimigo) override;
    void SwitchState(Zumbinana* inimigo) override;
};