#pragma once
#include "Inimigo.h"

class Inimigo2 : public Inimigo
{
private:
	int directionX;
	enum estado {
		Andando,
		Atacando,
	};


public:

	estado estado;
	Inimigo2(Lista<Jogador*>* listaJogadores = NULL, float posX = 0, float posY = 0, float vida = 5);
	~Inimigo2();

	void atualiza();
	void move();
	void SwitchState() { if (estado == Andando) { estado = Atacando; return; }estado = Andando; }

	void invertDirectionX() { directionX = -directionX; }
	void sacarArma();

};

