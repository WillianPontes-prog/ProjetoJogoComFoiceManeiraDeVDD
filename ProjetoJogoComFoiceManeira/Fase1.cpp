#include "Fase1.h"

Fase1::Fase1(GerenciadorGrafico* GG):
	Fase(GG)
{
	setTextura("Background_0.png");
	criaEntidades();
}

Fase1::~Fase1()
{
}

void Fase1::criaEntidades()
{
	criaJogador(120, 120, 5);
}
