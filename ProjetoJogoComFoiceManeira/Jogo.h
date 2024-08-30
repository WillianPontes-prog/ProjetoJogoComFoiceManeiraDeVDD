#pragma once
#include "GerenciadorGrafico.h"
#include <windows.h>
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
	
	sf::Texture texturaFim;
	sf::Texture texturaVenceu;
	sf::Sprite	spriteFinal;
	
	sf::Font font;
	std::string inputText;
	sf::Text text;

	int pontuacao;
	bool atualizarPontuacao;

	std::vector<sf::Text> rank;

public:

	enum modos {
		_menu,
		_menuFases,
		_fase1,
		_fase2,
		_fimDeJogo
	};

	modos rodando;

	Jogo();
	~Jogo();

	void executar();
	void setarModoDeJogo(modos m) { rodando = m; };
	void CriaFase1(bool n, bool carregar);
	void CriaFase2(bool n, bool carregar);

	void operator++(){pontuacao++; };
	int getPontuacao()			{ return pontuacao; };

	void atualizaPontuacao();

	
};

