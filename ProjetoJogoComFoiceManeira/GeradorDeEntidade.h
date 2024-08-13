#pragma once

#include "Fase.h"

class Fase;

class GeradorDeEntidade
{
private:
	Jogador*	criarJogador		(float posX = 0.f, float posY = 0.f);
	Inimigo*	criarInimigo		(float posX = 0.f, float posY = 0.f);
	Plataforma* criarPlataforma		(float posX = 0.f, float posY = 0.f);

	Fase* fase;

public:
	GeradorDeEntidade(Fase* _fase = nullptr);
	~GeradorDeEntidade();

	void setFase(Fase* fase) { this->fase = fase; };
	void executar(float posX = 0, float posY = 0, int n = 0);

};

