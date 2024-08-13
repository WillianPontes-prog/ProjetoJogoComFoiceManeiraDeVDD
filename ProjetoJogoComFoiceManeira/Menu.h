#pragma once
#include "Botao.h"
#include "Tecla.h"
#include "Jogo.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Jogo;
class Botao;

class Menu {
private:
	int continua;
	int botaoSelecionado;
	sf::RenderWindow* window;
	std::vector<Botao*> botoes;

	int flagBotaoPressionado;

	Jogo* jogo;

public:
	Menu(Jogo* jg);
	~Menu();
	void set_Window(sf::RenderWindow* window);
	void move();
	void atualiza();
};