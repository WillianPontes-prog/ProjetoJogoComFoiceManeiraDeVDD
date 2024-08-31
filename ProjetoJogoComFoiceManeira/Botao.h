#pragma once
#include <SFML/Graphics.hpp>
#include "Jogo.h"
#include "Entidades/Entidade.h"
#include <fstream>
#include <iostream>

class Jogo;

class Botao:public Entidades::Entidade {

public:
	enum tipoDoBotao {
		_NovoJogo,
		_NovoJogo2Jogadores,
		_CarregarJogo,
		_Fase1,
		_Fase2,
		_Sair,
	};

private:
	sf::Text text;
	sf::Font font;
	int pressionado;
	Jogo* jogo;

	tipoDoBotao tipo;

public:

	Botao(float x = 0, float y = 0.0, float largura = 0.0, float altura = 0.0, std::string text = "", tipoDoBotao _tipo = _Sair, Jogo* jg = nullptr);
	~Botao();

	void draw();
	void set_Color(sf::Color cor);
	void set_Pressed(bool VF);
	virtual void executar();
	void Salvar();
	void atualiza();
	void drawText();
	virtual json toJson() { return nullptr; };

	void carregarJogo();

};
