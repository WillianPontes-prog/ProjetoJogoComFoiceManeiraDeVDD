#pragma once
#include "Lista.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Ataque.h"

class GerenciadorDeColisao
{
private:
    Lista<Jogador*>* listaJogador;
    Lista<Inimigo*>* listaInimigos;
    Lista<Ataque*>* listaAtaqueJogador;
    Lista<Ataque*>* listaAtaqueInimigo;
    Lista<Plataforma*>* listaPlataforma;

    

public:
    GerenciadorDeColisao(Lista<Jogador*>* jogadores, Lista<Inimigo*>* inimigos, Lista<Ataque*>* ataquesJogador, Lista<Ataque*>* ataquesInimigo, Lista<Plataforma*>* plataformas);

    ~GerenciadorDeColisao();

    void tratarColisoes();

    
};
