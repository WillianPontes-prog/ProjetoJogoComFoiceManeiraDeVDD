#pragma once
#include "Inimigo.h"

class ZumbiFriorento : public Inimigo
{
private:
	int directionX;


public:
	ZumbiFriorento(Lista<Jogador*>* listaJogadores = NULL, float posX = 0, float posY = 0, float vida = 5);
	~ZumbiFriorento();

	void atualiza();
	void move();

	void invertDirectionX() { directionX = -directionX; }
	void sacarArma() {};

	void danificar(Jogador* j) {
		j->operator--();
	};
};

