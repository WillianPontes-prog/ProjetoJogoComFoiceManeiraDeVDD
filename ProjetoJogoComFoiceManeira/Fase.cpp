#include "Fase.h"


void Fase::inicializaElementos()
{
	std::srand(std::time(nullptr));

	Jogador* Player1 = new Jogador(32, 32);
	listaJogadores->push_back(Player1);

	Plataforma* chao = new Plataforma(window->getSize().x, 20.f, 0, window->getSize().y - 20.f);
	listaPlataforma->push_back(chao);

	chao = new Plataforma(100.f, window->getSize().y, 0, 150.f);
	listaPlataforma->push_back(chao);


	chao = new Plataforma(100.f,30.f, 70.f, 250.f);
	listaPlataforma->push_back(chao);

	chao = new Plataforma(190.f, 70.f, 100.f, 340.f);
	listaPlataforma->push_back(chao);

	chao = new Plataforma(window->getSize().x, 50.f, 300, window->getSize().y - 390.f);
	listaPlataforma->push_back(chao);

	Inimigo* inimigo = new Inimigo(30.f,30.f, 500.0, 50.0);
	listaInimigos->push_back(inimigo);

	//--------entregando elementos genericos para cada entidade--------\\
	//plataformas
	for (std::list<Plataforma*>::iterator it = listaPlataforma->begin(); it != listaPlataforma->end(); ++it) {
		(*it)->set_Window(window);
	}

	//inimigos
	for (std::list<Inimigo*>::iterator it = listaInimigos->begin(); it != listaInimigos->end(); ++it) {
		(*it)->set_Window(window);
		(*it)->set_listPlat(listaPlataforma);
		(*it)->set_listJogador(listaJogadores);
	}

	//Players
	for(std::list<Jogador*>::iterator it = listaJogadores->begin(); it != listaJogadores->end(); ++it){
		(*it)->set_Window(window);
		(*it)->set_listPlat(listaPlataforma);
	}


}

Fase::Fase(sf::RenderWindow* window)
{
	this->window = window;

	listaPlataforma		= new std::list<Plataforma*>();
	listaJogadores		= new std::list<Jogador*>();
	listaInimigos		= new std::list<Inimigo*>();


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


	for (std::list<Inimigo*>::iterator it = listaInimigos->begin(); it != listaInimigos->end(); ++it) {

		(*it)->atualiza();
	}
}
