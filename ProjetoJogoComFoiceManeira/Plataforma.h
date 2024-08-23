#pragma once
#include "Obstaculo.h"


class Plataforma : public Obstaculo
{
private:
	float atrito;

public:
	Plataforma(int posX = 0, int posY = 0);
	~Plataforma();

	void atualiza();
	float getAtrito() { return atrito; }
};

