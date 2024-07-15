#include "Fase.h"


void Fase::inicializaElementos()
{
	std::srand(std::time(nullptr));

	listaJogadores->push_back(j1);
	j1->set_listPlat(listaPlataforma);


	Plataforma* chao = new Plataforma(window->getSize().x, 100.f, 0, window->getSize().y - 200.f);
	chao->set_Window(window);
	listaPlataforma->push_back(chao);

	chao = new Plataforma(100.f, window->getSize().y, 0, 150.f);
	chao->set_Window(window);
	listaPlataforma->push_back(chao);

	chao = new Plataforma(window->getSize().x, 50.f, 300, window->getSize().y - 390.f);
	chao->set_Window(window);
	listaPlataforma->push_back(chao);

	//Inimigo* inimigo = new Inimigo(60.0,80.0, 50.0, 50.0, listaPlataforma);
	//inimigo->set_Window(window);
	//listaInimigos->push_back(inimigo);

	


}

Fase::Fase(Jogador* j1, sf::RenderWindow* window)
{
	this->window = window;

	this->j1 = j1;

	listaPlataforma		= new std::list<Plataforma*>();
	listaJogadores		= new std::list<Jogador*>();

	inicializaElementos();
}

Fase::~Fase()
{
}

void Fase::atualiza()
{
	//desenha todas entidades
	for (std::list<Plataforma*>::iterator it = listaPlataforma->begin(); it != listaPlataforma->end(); ++it) {

		(*it)->atualiza();
	}


	for (std::list<Jogador*>::iterator it = listaJogadores->begin(); it != listaJogadores->end(); ++it) {

		(*it)->atualiza();
	}
}
