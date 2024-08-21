#pragma once
#include "EntidadeColisao.h"
#include "Arma.h"

class Jogador : public EntidadeColisao
{
private:
	Lista<Projetil*>* listaProjetil;
	Arma* arma;

public:
	Jogador(float posX = 0, float posY = 0, int vida = 5);
	~Jogador();

	void move();
	void atualiza();
};

