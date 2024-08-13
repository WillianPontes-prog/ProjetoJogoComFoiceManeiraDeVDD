#pragma once
#include <SFML/Graphics.hpp>
#include "Jogo.h"

class Jogo;

class Botao {

public:
	enum tipoDoBotao {
		NovoJogo,
		CarregarJogo,
		Salvar,
		Sair,
	};

private:
	sf::RectangleShape body;
	sf::Text text;
	sf::Font font;
	sf::RenderWindow* window;
	int pressionado;
	Jogo* jogo;

	tipoDoBotao tipo;

public:

	Botao(sf::RenderWindow* w, float x = 0, float y = 0.0, float largura = 0.0, float altura = 0.0, std::string text = "", tipoDoBotao _tipo = Sair, Jogo* jg = nullptr);
	~Botao();

	void draw();
	void set_Color(sf::Color cor);
	void set_Window(sf::RenderWindow* window);
	void set_Pressed(bool VF);
	virtual void executar();
	void atualiza();



};