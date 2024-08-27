#pragma once
#include <SFML/Graphics.hpp>
#include "Jogo.h"
#include "Entidade.h"

class Jogo;

class Botao:public Entidade {

public:
	enum tipoDoBotao {
		_NovoJogo,
		_CarregarJogo,
		_Salvar,
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



};
