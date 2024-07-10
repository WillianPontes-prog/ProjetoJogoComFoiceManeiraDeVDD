#pragma once

#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidade.h"
#include "Plataforma.h"
#include "Ataque.h"

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <list>

class Fase {

private:
	std::list<Plataforma*>* listaPlataforma;
	std::list<Jogador*>*	listaJogadores;


	Jogador* j1;

	void inicializaElementos();


public:
	Fase(Jogador* j1 = NULL, sf::RenderWindow* window = NULL);
	~Fase();

	sf::RenderWindow* window;
	std::list<Plataforma*>* get_listaPlataforma() { return listaPlataforma; }
	std::list<Jogador*>* get_listaJogadores() { return listaJogadores; }
	void atualiza();


};