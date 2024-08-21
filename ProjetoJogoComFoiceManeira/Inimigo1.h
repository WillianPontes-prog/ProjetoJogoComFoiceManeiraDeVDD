#pragma once
#include "Inimigo.h"

class Inimigo1 : public Inimigo
{
private:

public:
	Inimigo1(Lista<Jogador*>* listaJogadores = NULL, float posX = 0, float posY = 0, float vida = 5);
	~Inimigo1();

	void atualiza();
	void move();

};

