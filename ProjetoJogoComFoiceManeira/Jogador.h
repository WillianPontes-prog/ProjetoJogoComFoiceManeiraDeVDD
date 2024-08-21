#pragma once
#include "EntidadeColisao.h"

class Jogador : public EntidadeColisao
{
private:

public:
	Jogador(float posX = 0, float posY = 0, int vida = 5);
	~Jogador();

	void move();
	void atualiza();
};

