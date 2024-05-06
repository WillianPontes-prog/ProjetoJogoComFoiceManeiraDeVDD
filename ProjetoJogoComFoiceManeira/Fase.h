#pragma once

#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidade.h"

#include <SFML/Graphics.hpp>

class Fase {

private:
	ListaEntidade* listaEntidades;

	Jogador* j1;

	void inicializaElementos();

public:
	Fase(Jogador* j1 = NULL, sf::RenderWindow* window = NULL);
	~Fase();

	sf::RenderWindow* window;
	ListaEntidade* getAllEntidade() { return listaEntidades; }

};