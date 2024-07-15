#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidade.h"
#include "Fase.h"
#include "Menu.h"

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


	Fase* fase1;
	Menu* menu;

public:
	Jogo();
	~Jogo();

	void Atualiza();

};