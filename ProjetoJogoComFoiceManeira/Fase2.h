#pragma once
#include "Fase.h"
#include "ZumbiDragao.h"



class Fase2 : public Fase
{
protected:
	int nChefao;

public:
	Fase2(bool Jogadores, Jogo* jg);
	~Fase2();

	void criaEntidades(float posX, float posY, int n);

	void criarChefao(float posX, float posY);

	void criaFogo(float posX = 0, float posY = 0);
};

