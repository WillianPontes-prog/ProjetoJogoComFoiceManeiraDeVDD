#pragma once
#include "Lista.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Ataque.h"
#include "Fase.h"

class Fase;

class GerenciadorDeColisao
{
private:
    Fase* fase;

public:
    GerenciadorDeColisao(Fase* fase);

    ~GerenciadorDeColisao();

    void tratarColisoes();

    
};
