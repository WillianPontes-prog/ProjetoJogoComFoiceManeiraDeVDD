#pragma once

#include "Estado.h"

class EstadoAndando : public Estado
{
public:
    void atualiza(Entidades::Personagens::Zumbinana* inimigo) ;
    void move(Entidades::Personagens::Zumbinana* inimigo) ;
    void sacarArma(Entidades::Personagens::Zumbinana* inimigo) ;
    void SwitchState(Entidades::Personagens::Zumbinana* inimigo) ;
};
