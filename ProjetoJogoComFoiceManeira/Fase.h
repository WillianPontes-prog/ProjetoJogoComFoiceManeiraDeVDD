#pragma once

#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidade.h"
#include "Plataforma.h"
#include "Ataque.h"
#include "Jogador.h"

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <list>

class Fase {

private:
	std::list<Plataforma*>* listaPlataforma;
	std::list<Jogador*>*	listaJogadores;
	std::list<Inimigo*>*	listaInimigos;

	void inicializaElementos();


public:
	Fase(sf::RenderWindow* window = nullptr);
	~Fase();

	sf::RenderWindow* window;
	std::list<Plataforma*>* get_listaPlataforma() { return listaPlataforma; }
	std::list<Jogador*>* get_listaJogadores() { return listaJogadores; }
	std::list<Inimigo*>* get_listaInimigos() { return listaInimigos; }
	void atualiza();


};