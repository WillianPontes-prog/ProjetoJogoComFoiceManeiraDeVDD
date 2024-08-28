#pragma once
#include "Entidade.h"
#pragma once
#include "Inimigo.h"

class Chefao : public Inimigo
{
private:
	int directionX;
	int chanceTeleporte;
	sf::Vector2f posicao1;
	sf::Vector2f posicao2;


public:
	Chefao(Lista<Jogador*>* listaJogadores = NULL, float posX = 0, float posY = 0, float vida = 100, int chanceTeleporte= 600, Arma* arma=nullptr);
	~Chefao();

	void atualiza();
	void move();

	void invertDirectionX() { directionX = -directionX; }
	void sacarArma();
	void setPosicao2(sf::Vector2f pos) { posicao2 = pos; }
	void Teleporte();
	virtual json toJson() { return nullptr; };	

	void danificar(Jogador* j) {
		j->operator--();
	};
};

