#include "Fase.h"


void Fase::inicializaElementos()
{
	std::srand(std::time(nullptr));

	listaJogadores->push_back(*j1);
	j1->set_listPlat(listaPlataforma);

	Plataforma* chao = new Plataforma(window->getSize().x, 100.f, 0, window->getSize().y - 200.f);
	chao->set_Window(window);
	listaPlataforma->push_back(*chao);

	chao = new Plataforma(window->getSize().x, 50.f, 300, window->getSize().y - 390.f);
	chao->set_Window(window);
	listaPlataforma->push_back(*chao);

	


}

Fase::Fase(Jogador* j1, sf::RenderWindow* window)
{
	this->window = window;

	this->j1 = j1;

	listaPlataforma		= new std::list<Plataforma>();
	listaJogadores		= new std::list<Jogador>();

	inicializaElementos();
}

Fase::~Fase()
{
}
