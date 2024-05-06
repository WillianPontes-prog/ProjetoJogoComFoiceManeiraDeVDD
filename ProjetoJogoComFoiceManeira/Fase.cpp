#include "Fase.h"

Fase::Fase(Jogador* j1)
{
	this->j1 = j1;
	listaEntidades = new ListaEntidade();
}

Fase::~Fase()
{
}
