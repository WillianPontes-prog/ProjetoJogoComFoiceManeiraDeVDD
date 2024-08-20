#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "Fase.h"
#include "Menu.h"

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

	Lista<Plataforma*>* listaPlataforma;
	Lista<Jogador*>* listaJogadores;
	Lista<Inimigo*>* listaInimigos;
	
public:
	Jogo();
	~Jogo();

	void Atualiza();

	void setGameState(pagina _state) { state = _state; }

};