#pragma once
#include "Entidade.h"
#include "Jogador.h"
class Obstaculo : public Entidade
{
protected:

public:
	Obstaculo(int posX = 0, int posY = 0);
	~Obstaculo();

	virtual void atualiza() = 0;
	virtual void Obstacular(Jogador* j) = 0;
};

