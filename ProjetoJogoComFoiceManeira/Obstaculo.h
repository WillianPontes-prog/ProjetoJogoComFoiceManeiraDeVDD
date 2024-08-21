#pragma once
#include "Entidade.h"

class Obstaculo : public Entidade
{
protected:

public:
	Obstaculo(int posX = 0, int posY = 0);
	~Obstaculo();

	void atualiza() = 0;
};

