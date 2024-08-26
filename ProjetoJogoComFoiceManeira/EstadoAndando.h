#pragma once
#pragma once
#include "Estado.h"

class EstadoAndando : public Estado
{
public:
    void atualiza(Inimigo2* inimigo) override;
    void move(Inimigo2* inimigo) override;
    void sacarArma(Inimigo2* inimigo) override;
    void SwitchState(Inimigo2* inimigo) override;
};
