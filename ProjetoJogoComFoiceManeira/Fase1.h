#pragma once
#include "Fase.h"

class Fase1 : public Fase
{
protected:

public:
	Fase1();
	~Fase1();

	void criaEntidades(float posX, float posY, int n);

	void criarObstaculo2(float posX, float posY);

};

