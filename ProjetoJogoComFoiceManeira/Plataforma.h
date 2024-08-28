#pragma once
#include "Obstaculo.h"
#include "Jogador.h"

class Plataforma : public Obstaculo
{
private:
	float atrito;

public:
	Plataforma(int posX = 0, int posY = 0);
	~Plataforma();

	void atualiza();
	float getAtrito() { return atrito; }
	void Obstacular(Jogador* j);
	json toJson() { return nullptr; };
};

