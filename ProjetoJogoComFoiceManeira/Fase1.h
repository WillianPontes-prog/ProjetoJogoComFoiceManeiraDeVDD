#pragma once
#include "Fase.h"



class Fase1 : public Fase
{
protected:
	int numZumbiFriorento[4];

	void carregarFase();

public:
	Fase1(bool Jogadores, Jogo* jg, bool carregar = false);
	~Fase1();

	void criaEntidades(float posX, float posY, int n);

	void criarTeleporte(float posX, float posY);

	void criarZumbiFriorento(float posX = 0, float posY = 0, float vida = 5);
};

