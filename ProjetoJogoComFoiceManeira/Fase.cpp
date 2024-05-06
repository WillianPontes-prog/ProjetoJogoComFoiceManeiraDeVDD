#include "Fase.h"
#include <cstdlib>
#include <ctime>

void Fase::inicializaElementos()
{
	std::srand(std::time(nullptr));

	listaEntidades->LEs.push(j1);
	for (int i = 0; i < 3; i++) {
		
		Inimigo* iniTemp = new Inimigo(rand() % (window->getSize().x), rand() % (window->getSize().y));
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
