#pragma once
#include "EntidadeColisao.h"
#include "Jogador.h"
#include "Lista.h"

class Inimigo : public EntidadeColisao {

protected:
	Lista<Jogador*>* listaJogadores;

public:
	Inimigo(Lista<Jogador*>* listaJogadores = NULL, float posX = 0, float posY = 0, float vida = 5);
	~Inimigo();

	sf::Vector2f BuscarJogador();

	virtual void atualiza() = 0;

	virtual void move() = 0;
};