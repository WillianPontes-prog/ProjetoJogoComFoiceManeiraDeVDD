#pragma once
#include "GerenciadorGrafico.h"
#include "fase1.h"
#include "Menu.h"

class Menu;

class Jogo
{
private:


	

	GerenciadorGrafico* gerenciadorGrafico;
	Fase1* f1;
	Menu* menu;


public:

	enum modos {
		_menu,
		_fase1,
		_fase2
	};

	modos rodando;

	Jogo();
	~Jogo();

	void executar();
	void setarModoDeJogo(modos m) { rodando = m; };
};

