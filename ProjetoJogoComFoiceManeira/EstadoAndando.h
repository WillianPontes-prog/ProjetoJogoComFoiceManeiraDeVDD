#pragma once

#include "Estado.h"

class EstadoAndando : public Estado
{
public:
    void atualiza(Personagens::Zumbinana* inimigo) ;
    void move(Personagens::Zumbinana* inimigo) ;
    void sacarArma(Personagens::Zumbinana* inimigo) ;
    void SwitchState(Personagens::Zumbinana* inimigo) ;
};
