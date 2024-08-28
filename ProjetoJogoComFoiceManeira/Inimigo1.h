#pragma once
#include "Inimigo.h"

class Inimigo1 : public Inimigo
{
private:
	int directionX;


public:
	Inimigo1(Lista<Jogador*>* listaJogadores = NULL, float posX = 0, float posY = 0, float vida = 5);
	~Inimigo1();

	void atualiza();
	void move();

	void invertDirectionX() { directionX = -directionX; }
	void sacarArma() {};

	virtual json toJson() { return nullptr; };

	void danificar(Jogador* j) {
		j->operator--();
	};
};

