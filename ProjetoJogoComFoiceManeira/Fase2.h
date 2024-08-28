#pragma once
#include "Fase.h"
#include "ZumbiDragao.h"



class Fase2 : public Fase
{
protected:
	int nChefao;

	void carregarFase();

public:
	Fase2(bool Jogadores, Jogo* jg, bool carregar = false);
	~Fase2();

	void criaEntidades(float posX, float posY, int n);

	void criarChefao(float posX, float posY, int vida);

	void criarFogo(float posX = 0, float posY = 0);
};

