#pragma once
#include "GerenciadorGrafico.h"
#include "fase1.h"

class Jogo
{
private:
	GerenciadorGrafico* gerenciadorGrafico;
	Fase1* f1;


public:
	Jogo();
	~Jogo();

	void executar();
};

