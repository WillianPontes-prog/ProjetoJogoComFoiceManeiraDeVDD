#pragma once
#include "Fase.h"
#include "Obstaculo2.h"
#include "Obstaculo1.h"

class Fase;

class GerenciadorDeColisoes
{
private:
	Fase* fase;


public:
	GerenciadorDeColisoes(Fase* fase);
	~GerenciadorDeColisoes();

	void tratarColisoes();

	int ChecarColisao(const sf::RectangleShape& rect1, const sf::RectangleShape& rect2) {
		sf::FloatRect bounds1 = rect1.getGlobalBounds();
		sf::FloatRect bounds2 = rect2.getGlobalBounds();
		return bounds1.intersects(bounds2);
	}

	int NumeroMinimo(float valor)
	{
		if (valor == 0) { return 0; }
		else { return (valor / abs(valor)); }
	}

	void danoJogador(Jogador* jogador, int dirX);

	
};

