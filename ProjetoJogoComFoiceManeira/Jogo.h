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
	enum pagina {
		MenuInicial,
		EmJogo
	};

private:

	Fase* fase1;
	Menu* menu;

	pagina state = MenuInicial;

	sf::RenderWindow* window;

	std::list<Plataforma*>* listaPlataforma;
	std::list<Jogador*>* listaJogadores;
	std::list<Inimigo*>* listaInimigos;
	
public:
	Jogo();
	~Jogo();

	void Atualiza();

	void setGameState(pagina _state) { state = _state; }

};