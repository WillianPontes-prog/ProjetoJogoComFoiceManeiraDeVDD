#pragma once
#include "Botao.h" 
#include "Jogo.h"
#include"GerenciadorDeComandos.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Jogo;
class Botao;

class Menu:public Ente {
private:
	int continua;
	int botaoSelecionado;
	std::vector<Botao*> botoes;
	std::vector<Botao*> botoesFases;

	int flagBotaoPressionado;

	Jogo* jogo;

public:
	Menu(Jogo* jg);
	~Menu();
	void move();
	void atualiza();

	bool fases;

};