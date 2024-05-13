#pragma once
#include"Entidade.h"
class Ataque : protected Entidade {
private:
	float tamanho, velocidade, direção, dano;

public:
	Ataque(float tam = 0, float vel = 0, float dir = 0, float dan = 0);
	~Ataque();

};