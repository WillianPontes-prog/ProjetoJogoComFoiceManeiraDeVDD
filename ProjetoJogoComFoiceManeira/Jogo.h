#pragma once
#include "GerenciadorGrafico.h"
#include "fase1.h"
#include "fase2.h"
#include "Menu.h"

class Menu;

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
		_fase1,
		_fase2
	};

	modos rodando;

	Jogo();
	~Jogo();

	void executar();
	void setarModoDeJogo(modos m) { rodando = m; };
	void CriaFase1(bool n) { if (!f1) { delete f1; } f1 = new Fase1(n); }
	void CriaFase2(bool n) { if (!f2) { delete f2; } f2 = new Fase2(n); }
};

