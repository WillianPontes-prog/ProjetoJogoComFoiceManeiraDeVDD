#pragma once
#include "Fase.h"

class Fase1 : public Fase
{
protected:

public:
	Fase1(bool Jogadores);
	~Fase1();

	void criaEntidades(float posX, float posY, int n);

	void criarObstaculo2(float posX, float posY);

	void criarInimigo1(float posX = 0, float posY = 0, float vida = 5);
};

