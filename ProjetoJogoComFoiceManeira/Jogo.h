#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "Fase.h"
#include "Menu.h"

#include<list>

class Menu;

class Jogo {

public:
	enum page {
		InitialMenu,
		InGame
	};

private:

	page state = InitialMenu;

	sf::RenderWindow window;

	std::list<Plataforma*>* listaPlataforma;
	std::list<Jogador*>* listaJogadores;
	std::list<Inimigo*>* listaInimigos;


	Fase* fase1;
	Menu* menu;
	
public:
	Jogo();
	~Jogo();

	void Atualiza();

	void setGameState(page _state) { state = _state; }

};