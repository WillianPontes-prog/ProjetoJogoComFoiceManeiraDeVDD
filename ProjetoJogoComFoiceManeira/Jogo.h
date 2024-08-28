#pragma once
#include "GerenciadorGrafico.h"

#include "Menu.h"

class Menu;
class Fase1;
class Fase2;

class Jogo
{
private:
	GerenciadorGrafico* gerenciadorGrafico;
	Fase1* f1;
	Fase2* f2;

	Menu* menu;
	


public:

	enum modos {
		_menu,
		_menuFases,
		_fase1,
		_fase2
	};

	modos rodando;

	Jogo();
	~Jogo();

	void executar();
	void setarModoDeJogo(modos m) { rodando = m; };
	void CriaFase1(bool n, bool carregar);
	void CriaFase2(bool n, bool carregar);
};

