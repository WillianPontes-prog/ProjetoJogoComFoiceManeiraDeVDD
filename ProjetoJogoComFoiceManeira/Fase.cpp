#include "Fase.h"


void Fase::inicializaElementos()
{
	std::srand(std::time(nullptr));

	listaEntidades->LEs.push(j1);
	j1->set_LEs(listaEntidades);

	/*
	for (int i = 0; i < 3; i++) {
		
		Inimigo* iniTemp = new Inimigo(rand() % (window->getSize().x), rand() % (window->getSize().y));
		iniTemp->set_Window(window);

		listaEntidades->LEs.push(iniTemp);
	}
	*/

	Plataforma* chao = new Plataforma(window->getSize().x, 100.f, 0, window->getSize().y - 200.f);
	chao->set_Window(window);
	listaEntidades->LEs.push(chao);

	chao = new Plataforma(window->getSize().x, 50.f, 300, window->getSize().y - 390.f);
	chao->set_Window(window);
	listaEntidades->LEs.push(chao);

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
