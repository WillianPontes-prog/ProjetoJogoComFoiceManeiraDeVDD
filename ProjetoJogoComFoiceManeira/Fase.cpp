#include "Fase.h"

void Fase::inicializaElementos()
{
	listaEntidades->LEs.push(j1);
	for (int i = 0; i < 3; i++) {
		Inimigo* iniTemp = new Inimigo(20.0 * i, 10.0 * i);
		iniTemp->set_Window(window);

		listaEntidades->LEs.push(iniTemp);
	}
}

Fase::Fase(Jogador* j1, sf::RenderWindow* window)
{
	this->window = window;

	this->j1 = j1;
	listaEntidades = new ListaEntidade();

	inicializaElementos();
}

Fase::~Fase()
{
}
