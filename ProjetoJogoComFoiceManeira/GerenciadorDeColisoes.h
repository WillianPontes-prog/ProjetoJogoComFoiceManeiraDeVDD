#pragma once
#include "Fase.h"
#include "ObstaculoDano.h"
#include "ObstaculoTeleporte.h"
#include "Inimigo.h"

class Fase;
class MudarFase;

class GerenciadorDeColisoes
{
private:
	Lista<Jogador*>*	listaJogador;
	Lista<Plataforma*>* listaPlataforma;
	Lista<Inimigo*>*	listaInimigos;
	Lista<Obstaculo*>*	listaObstaculos;

	MudarFase* mudarFase;

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

	Lista<Jogador*>* getListaJogadores() { return listaJogador; };
	Lista<Plataforma*>* getListaPlataforma() { return listaPlataforma; };
	Lista<Inimigo*>* getListaInimigos() { return listaInimigos; };
	Lista<Obstaculo*>* getListaObstaculos() { return listaObstaculos; };
	
	MudarFase* getMudarFase() { return mudarFase; };
	void setMudarFase(MudarFase* m) { mudarFase = m; };
};

