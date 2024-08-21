#pragma once
#include "Fase.h"

class Fase;

class GerenciadorDeColisoes
{
private:
	Fase* fase;

public:
	GerenciadorDeColisoes(Fase* fase);
	~GerenciadorDeColisoes();

	void tratarColisoes();
};

