#pragma once

#include "Jogador.h"
#include "ListaEntidade.h"

class Fase {

private:
	ListaEntidade* listaEntidades;

	Jogador* j1;

public:
	Fase(Jogador* j1);
	~Fase();


};