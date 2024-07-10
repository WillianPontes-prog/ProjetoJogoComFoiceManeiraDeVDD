#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidade.h"
#include "Fase.h"

#include<list>

class Jogo {

private:

	enum page {
		InitialMenu,
		InGame
	};

	page state = InitialMenu;

	sf::RenderWindow window;

	Jogador* Player1;

	std::list<Plataforma*>* listaPlataforma;
	std::list<Jogador*>* listaJogadores;
	std::list<Inimigo*>* listaInimigos;

	Fase* fase1;

public:
	Jogo();
	~Jogo();

	void Atualiza();

};